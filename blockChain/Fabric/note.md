* `configtxgen`是生产 channel 配置的工具
* `channel.tx`的来源, 作用 (更新 channel 配置的 transaction)
* `commiter`: 记账 peer, 每个 peer 基本都是.
* 证书分类: Ecert(身份认证), tCert(交易认证), Tls(通信认证)
* Channel 配置: `Admins, Writer, Readers`的真正含义

#### CA

* `.csr`: (Certificate Signing Request), 申请返回的是 publick certificate.
* PEM-encoded: `X.509`证书 可以使用这种格式保存证书.
* `certfile`存储的自己证书信息(包含自己的公钥), 便于第三方连接前认证.
* `keyfile`: 存储自己的私钥
