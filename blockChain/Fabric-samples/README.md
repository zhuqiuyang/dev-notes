### 1. Register and enroll new users in Organization - Org1 涉及的步骤

1.  `helper/getClientForOrg()`

* `getRegisteredUser()` 先执行 `getClientForOrg()`
* `getConfigSetting` -> `hfc/Config.js:: Constructor`

```js
async function getClientForOrg(userorg, username) {
  logger.debug("getClientForOrg - ****** START %s %s", userorg, username);
  // get a fabric client loaded with a connection profile for this org
  let config = "-connection-profile-path";

  // 找到并加载配置文件!
  let client = hfc.loadFromConfig(hfc.getConfigSetting("network" + config));

  // 加载连接指定org的 client config
  client.loadFromConfig(hfc.getConfigSetting(userorg + config));

  // this will create both the state store and the crypto store 基于client config
  await client.initCredentialStores();

  //...

  return client;
}
```

#### fabcar 例子

* admin 是在 启动网络时, CA Server 中配置的. (basic-network/docker-compse.yml 中: `fabric-ca-server start -b admin:adminpw -d`)
* 通过`enroll()`获取到 admin 的 eCert, 用于后续 register 和 enroll 新的 user

```js
// A. enrollAdmin.js
// 1. 获取admin
fabric_client.getUserContext("admin", true);

// 2. 不存在向ca注册
fabric_ca_client
  // 2.1 EnrollmentRequest: https://fabric-sdk-node.github.io/global.html#EnrollmentRequest
  .enroll({
    enrollmentID: "admin",
    enrollmentSecret: "adminpw"
  })
  .then(enrollment => {
    // enrollment: "key": for private key, "certificate": the signed certificate

    // 2. createUser(UserOpts): https://fabric-sdk-node.github.io/global.html#UserOpts
    // Returns a `User` object with signing identities
    return fabric_client.createUser({
      username: "admin",
      mspid: "Org1MSP",
      cryptoContent: {
        privateKeyPEM: enrollment.key.toBytes(),
        signedCertPEM: enrollment.certificate
      }
    });
  })
  .then(user => {
    admin_user = user;
    // 3. set
    return fabric_client.setUserContext(admin_user);
  });
```

```js
// B. fabcar/registerUser.js
// admin 注册使用enroll, user 使用register
then(user_from_store => {
  if (user_from_store && user_from_store.isEnrolled()) {
    console.log("Successfully loaded admin from persistence");
    admin_user = user_from_store;
  } else {
    throw new Error("Failed to get admin.... run enrollAdmin.js");
  }

  // at this point we should have the admin user
  // first need to register the user with the CA server
  // 注册user时需传入 `registrar`(管理员-admin), 作为第二个参数
  return fabric_ca_client.register(
    { enrollmentID: "user1", affiliation: "org1.department1", role: "client" },
    admin_user
  );
})
  .then(secret => {
    // next we need to enroll the user with CA server
    console.log("Successfully registered user1 - secret:" + secret);

    return fabric_ca_client.enroll({
      enrollmentID: "user1",
      enrollmentSecret: secret
    });
  })
  .then(enrollment => {
    console.log('Successfully enrolled member user "user1" ');
    return fabric_client.createUser({
      username: "user1",
      mspid: "Org1MSP",
      cryptoContent: {
        privateKeyPEM: enrollment.key.toBytes(),
        signedCertPEM: enrollment.certificate
      }
    });
  });
```

```js
// C. query.js cc查询

// 1. 首先: setup the fabric network
var channel = fabric_client.newChannel("mychannel");
var peer = fabric_client.newPeer("grpc://localhost:7051");
channel.addPeer(peer);

// 2. chaincode 查询
const request = {
  //targets : --- letting this default to the peers assigned to the channel
  chaincodeId: "fabcar",
  fcn: "queryAllCars",
  args: [""]
};

// send the query proposal to the peer
return channel.queryByChaincode(request);
// Channel.js: ->
return channel.sendTransactionProposal();
// -> static function
return Channel.sendTransactionProposal(
  request,
  this._name,
  this._clientContext,
  timeout
);
// 此处包含 signed_proposal的生成过程.
// ->
return clientUtils.sendPeersProposal(request.targets, signed_proposal, timeout);
// clientUtils.js: 对每一个target调用 ->
peer.sendProposal();
```

```js
// D. invoke.js

channel.sendTransaction(request);

eventHub.re
```

#### Client

##### state store

* A `state store` 辅助 SDK 存储一些关键信息 to be used across server restarts/crashes. 此外, 还存储了 signing identities (instances of the User class).
* SDK 默认存储在 file 中.
* `Channel`class 使用`state store`存储一些敏感信息 (private key & cert)

> fabric-client-kv-org1/admin

```json
{
  "name": "admin",
  "mspid": "Org1MSP",
  "roles": null,
  "affiliation": "",
  "enrollmentSecret": "",
  "enrollment": {
    "signingIdentity":
      "252de1e514775472546bcc55691bdf4188699aa24d47f437371856c5a8dbceb2",
    "identity": {
      "certificate":
        "-----BEGIN CERTIFICATE-----\nMIICATCCAaigAwIBAgIUGi/h5Eya0PMuhhMbQ8ym3omaZzwwCgYIKoZIzj0EAwIw\nczELMAkGA1UEBhMCVVMxEzARBgNVBAgTCkNhbGlmb3JuaWExFjAUBgNVBAcTDVNh\nbiBGcmFuY2lzY28xGTAXBgNVBAoTEG9yZzEuZXhhbXBsZS5jb20xHDAaBgNVBAMT\nE2NhLm9yZzEuZXhhbXBsZS5jb20wHhcNMTgwNDI1MDgzNjAwWhcNMTkwNDI1MDg0\nMTAwWjAhMQ8wDQYDVQQLEwZjbGllbnQxDjAMBgNVBAMTBWFkbWluMFkwEwYHKoZI\nzj0CAQYIKoZIzj0DAQcDQgAEu2A0fl2XDB3lZr6IpozyZdb7vkT6lgIwDDi5Q4uP\nxia33dsb2PVO9z9ftuutZng0xrFmmhlcWhMmNpoJHFunMqNsMGowDgYDVR0PAQH/\nBAQDAgeAMAwGA1UdEwEB/wQCMAAwHQYDVR0OBBYEFDGHPA7RzCMLr36EwziDOIHO\nHkGVMCsGA1UdIwQkMCKAIA5ykiTos/MXhMipPFuO9vTByR2ebld8RcMxY2Cf5AAR\nMAoGCCqGSM49BAMCA0cAMEQCIFxlHwwbGdSV4REnbx7pn76qAOhfQ72VGtLculsW\nUtvUAiBTWYJoz7czHOZvIcvMkEcUtRwqy2hWi0QR4lkO87p9pA==\n-----END CERTIFICATE-----\n"
    }
  }
}
```

#### crypto store

> 存储成对的公/私钥

> `require('fabric-ca-client')` 时使用的是`FabricCAServices`, 其内部调用了`FabricCAClient` class 用于与 CA Client 交互.

#### FabricCAClient

> Client for communciating with the Fabric CA APIs

```js
register(
  enrollmentID,
  enrollmentSecret,
  role,
  affiliation,
  maxEnrollments,
  attrs,
  signingIdentity
);
```

#### FabricCAServices

> This is an implementation of the member service client which communicates with the Fabric CA server.
>
> extend 自 BaseClient

```js
register(req, registrar);
```
