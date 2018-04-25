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

### fabcar

#### enroll

```js
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
