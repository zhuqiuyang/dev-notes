const { randomBytes } = require('crypto')
const secp256k1 = require('./')
// or require('secp256k1/elliptic')
//   if you want to use pure js implementation in node

// generate message to sign
const msg = randomBytes(32)

const privKey = Buffer.from('74eff5fe9f1465f8d5c567a3310e47fefd6e2f173d3905ae531e0d8054190584', 'hex')

console.log('private key: ', privKey.toString('hex'))

// get the public key in a compressed format
const pubKey = secp256k1.publicKeyCreate(privKey)

const start = Date.now()

// sign the message

let i = 10000

const sigObj = secp256k1.sign(msg, privKey)
while (i--) {
  const sigObj1 = secp256k1.sign(msg, privKey)
}

console.log('time: ', Date.now() - start)

// verify the signature
console.log(secp256k1.verify(msg, sigObj.signature, pubKey))
// => true
