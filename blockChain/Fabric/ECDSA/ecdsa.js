const crypto = require('crypto')

const privateKey = `-----BEGIN PRIVATE KEY-----
MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgdO/1/p8UZfjVxWej
MQ5H/v1uLxc9OQWuUx4NgFQZBYShRANCAASFn9tdSC6AF8QWwIHzCDkYzGgb6Z7I
EN/0A41RUTRc7to4pJAfwbCBXkzMSa698Lv0yolH4dnSGjrEnk2lhI8C
-----END PRIVATE KEY-----`

const start = Date.now()
let i = 2000
while (i-- > 0) {
  const sign = crypto.createSign('ecdsa-with-SHA1')
  sign.write('some data to signsome data to signsome data to signsome data to signsome data to sign')
  sign.end()
  sign.sign(privateKey, 'hex')
}
console.log(Date.now() - start)
// console.log(sign.sign(privateKey, 'hex'));
