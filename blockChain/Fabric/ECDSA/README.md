- 查看`cert.pem`(CA 颁发的 X.509 证书)

```sh
> openssl x509 -in cert.pem -text -noout
Certificate:
    Data:
        Version: 3 (0x2)
        Serial Number:
            7d:d1:5d:1c:77:e3:e0:11:f6:5b:42:c7:48:93:34:32:6f:62:97:0f
    Signature Algorithm: ecdsa-with-SHA256
        Issuer: C=US, ST=North Carolina, O=Hyperledger, OU=client, CN=admin
        Validity
            Not Before: Jun 19 09:43:00 2018 GMT
            Not After : Jun 19 09:48:00 2019 GMT
        Subject: C=US, ST=North Carolina, O=Hyperledger, OU=client, CN=admin
        Subject Public Key Info:
            Public Key Algorithm: id-ecPublicKey
                Public-Key: (256 bit)
                pub:
                    04:85:9f:db:5d:48:2e:80:17:c4:16:c0:81:f3:08:
                    39:18:cc:68:1b:e9:9e:c8:10:df:f4:03:8d:51:51:
                    34:5c:ee:da:38:a4:90:1f:c1:b0:81:5e:4c:cc:49:
                    ae:bd:f0:bb:f4:ca:89:47:e1:d9:d2:1a:3a:c4:9e:
                    4d:a5:84:8f:02
                ASN1 OID: prime256v1
                NIST CURVE: P-256
        X509v3 extensions:
            X509v3 Key Usage: critical
                Digital Signature
            X509v3 Basic Constraints: critical
                CA:FALSE
            X509v3 Subject Key Identifier:
                61:81:8E:F9:E2:46:E2:30:C9:99:D1:4C:4F:80:41:FE:D7:7E:22:F1
            X509v3 Subject Alternative Name:
                DNS:localhost
    Signature Algorithm: ecdsa-with-SHA256
         30:45:02:21:00:e3:ae:f7:c2:4d:18:19:f3:8e:48:5d:ff:0a:
         f5:d4:1b:9c:26:a4:76:d9:1f:f7:8b:e3:96:3e:c7:81:b7:64:
         01:02:20:33:f3:90:da:34:16:e8:43:95:f7:83:ee:02:90:23:
         75:8f:34:5d:c3:3e:16:04:0e:bd:89:22:41:95:4f:f2:b7
```

- ecc 私钥查看

```sh
> openssl ec -in 53c7b77d8cc13731f095cf593e575f4a1dfbc17497d9c1149dc65dafa9a6f36c_sk -noout -text
read EC key
Private-Key: (256 bit)
priv:
    74:ef:f5:fe:9f:14:65:f8:d5:c5:67:a3:31:0e:47:
    fe:fd:6e:2f:17:3d:39:05:ae:53:1e:0d:80:54:19:
    05:84
pub:
    04:85:9f:db:5d:48:2e:80:17:c4:16:c0:81:f3:08:
    39:18:cc:68:1b:e9:9e:c8:10:df:f4:03:8d:51:51:
    34:5c:ee:da:38:a4:90:1f:c1:b0:81:5e:4c:cc:49:
    ae:bd:f0:bb:f4:ca:89:47:e1:d9:d2:1a:3a:c4:9e:
    4d:a5:84:8f:02
ASN1 OID: prime256v1
NIST CURVE: P-256
```

- ECDSA 签名产生`rG`(r)和`s`, 和 message 一起发给对方.
- 列出`openssl`支持 curve list
- node 官方`crypto`不支持`ECDSA_SHA256`
  > https://nodejs.org/api/crypto.html
  >
  > This does not work for all signature algorithms, such as 'ecdsa-with-SHA256'. Use digest names instead.
