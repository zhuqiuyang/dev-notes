> http://hyperledger-fabric-ca.readthedocs.io/en/latest/users-guide.html

## 0.

### 重点总结

* 只有已注册(enroll)的用户, 可以登记新用户(在自己管辖范围内)
* enroll 是注册, register 是登记. admin 默认由 ca-server`-b`指定(已登记), 所以可以直接 enroll.

### CA feature:

* 颁发 Enrollment certificate (Ecert- 身份证书)

## 1. Overview

* `identities and certificates`信息存储在 LDAP(Lightweight Directory Access Protocol 轻量目录访问协议) 或者 database 中

## 2. Getting Started

### Start Server with Docker

* https://hub.docker.com/r/hyperledger/fabric-ca/tags/
  `docker-compose up -d`

### CLI

* http://hyperledger-fabric-ca.readthedocs.io/en/latest/servercli.html
* http://hyperledger-fabric-ca.readthedocs.io/en/latest/clientcli.html

### Configuration Settings

配置优先级依次为:

1.  CLI flags
2.  Environment variables
3.  Configuration file

`fabric-ca-server --help`: 查看 CLI 使用

## 4. Fabric CA Server

### Initializing the server

```sh
fabric-ca-server init -b admin:adminpw
```

* 如果没有配置`ldap.enabled`,`-b`必须提供

* Server 配置包含 Certificate Signing Request (CSR) section, 例子如下:

> 申请 cert 所需填写的信息.

```sh
cn: fabric-ca-server
names:
   - C: US
     ST: "North Carolina"
     L:
     O: Hyperledger
     OU: Fabric
hosts:
  - host1.example.com
  - localhost
ca:
   expiry: 131400h
   pathlength: 1
```

* `fabric-ca-server init`使用 self-signed CA certificate, 除非指定一个父 CA
  * `-u <parent-fabric-ca-server-URL>`
* `fabric-ca-server init`默认会生成一个 `fabric-ca-server-config.yaml` file 在 server 的 home 目录
* 人工配置 CA 需要提供`ca.certfile` and `ca.keyfile`两个文件, 并满足
  * must be PEM-encoded
  * must not be encrypted

### Starting the server

```sh
fabric-ca-server start -b <admin>:<adminpw>
```

server 会自生成 `ca-cert.pem` and `ca-key.pem` 和 `default configuration` file if it does not exist.

### Enrolling an intermediate CA

intermediate CA must enroll with a parent CA , 其方式与 a `fabric-ca-client` enrolls with a CA 相同.

### Upgrading the server

5.  确认 ca-server process is avaiable

```sh
fabric-ca-client getcacert -u http://<host>:7054
```

## 5. CA Client

### Enrolling the bootstrap identity

`fabric-ca-client enroll` will Enroll a Identify. 存储 (ECert)及其对应的 private key and CA certificate chain PEM files 在 Fabric CA CLient `msp`目录的子目录下.

### Registering a new identity (\*)

> 需要 check (包含 affiliation): http://hyperledger-fabric-ca.readthedocs.io/en/latest/users-guide.html#registering-a-new-identity

### Attribute-Based Access Control

ABAC can be made by chaincode, 原理:

* identity’s `ECert` may contain one or more attribute name and value.
* CC extracts an `attribute’s value` to 作为访问控制依据.

## 6. HSM

* 私钥存储在`PEM-encoded`的 file 中 (CA server/client 默认 )
* 可以存于 HSM (Hardware Security Module), 通过 PKCS11 APIs:
  * 需要在 `BCCSP` (BlockChain Crypto Service Provider) section of the server’s or client’s configuration file 配置.

## 7. File Formats

* CA Server 配置文件格式: http://hyperledger-fabric-ca.readthedocs.io/en/latest/serverconfig.html

* CA Client 配置文件格式: http://hyperledger-fabric-ca.readthedocs.io/en/latest/clientconfig.html

## 集群搭建

```sh
export FABRIC_CA_CLIENT_HOME=$HOME/fabric-ca/clients/admin
fabric-ca-server start -b admin:adminpw --db.type mysql --db.datasource root:rootpw@tcp(db:3306)/fabric_ca?parseTime=true

# in db container
mysql -uroot -p

show databases;
user fabric-ca;
show tables;
```
