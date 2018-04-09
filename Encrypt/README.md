## Encrypt

* RSA 公钥加密算法的一种 (三个人名字)
* AES（Advanced Encryption Standard, 高级加密标准）, 
  * CBC(Cipher-Block Chaining)
RSA的解密耗时约等于 AES 解密耗时的 100 倍, 用RSA加密AES的`对称秘钥`, 提高速度.
> HTTPS本身就是一种很安全的协议.
* SHA(Secure Hash Algorithm, 安全散列算法)
* Hmac(Hash-based Message Authentication Code): 需要Hash算法(MD5/SHA256), 和一个key.

> Cipher (加密Class), Decipher (解密Class)

### 数字签名:
http://www.ruanyifeng.com/blog/2011/08/what_is_a_digital_signature
> Digest(摘要), 是内容的`Hash`值.
> Signature(数字签名), 是对`Digest`的公钥加密结果. (通过Signatur解密出Digest, 作比对)