## Encrypt

- RSA 公钥加密算法的一种 (三个人名字)
- AES（Advanced Encryption Standard, 高级加密标准）,
  - CBC(Cipher-Block Chaining)
    > RSA 的解密耗时约等于 AES 解密耗时的 100 倍, 用 RSA 加密 AES 的`对称秘钥`, 提高速度.
    >
    > HTTPS 本身就是一种很安全的协议.
- SHA(Secure Hash Algorithm, 安全散列算法)
- Hmac(Hash-based Message Authentication Code): 需要 Hash 算法(MD5/SHA256), 和一个 key.

> Cipher (加密 Class), Decipher (解密 Class)

### 数字签名:

http://www.ruanyifeng.com/blog/2011/08/what_is_a_digital_signature

- Digest(摘要), 是内容的`Hash`值.
- Signature(数字签名), 是对`Digest`的公钥加密结果. (通过 Signatur 解密出 Digest, 作比对)

### 图解密码技术

- 加密用`公钥(E)`, 签名用`私钥(D)`
- 离散对数, `MOD`(模)本质是`时钟转动`

#### RSA Signature

> https://www.youtube.com/watch?v=DIfOvWymmP0
