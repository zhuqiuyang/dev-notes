### invoke 签名

```js
Channel.sendTransactionProposal()
// -> Channel
header = clientUtils.buildHeader(signer, channelHeader, request.txId.getNonce())
proposal = clientUtils.buildProposal(invokeSpec, header, request.transientMap)
let signed_proposal = clientUtils.signProposal(signer, proposal)
// -> clientUtils
module.exports.signProposal = function(signingIdentity, proposal) {
  const proposal_bytes = proposal.toBuffer()
  // sign the proposal
  const sig = signingIdentity.sign(proposal_bytes)
  // ...
}
```

```js
// signer
var signer = null
if (request.signer) {
  signer = request.signer
} else {
  signer = clientContext._getSigningIdentity(request.txId.isAdmin())
}

// Channel constructor
constructor(name, clientContext) {}
// Client
_getSigningIdentity()
this._adminSigningIdentity = new SigningIdentity(certificate, public_key, mspid, crypto_suite, new Signer(crypto_suite, key));
// Client
var idModule = require('./msp/identity.js');
var SigningIdentity = idModule.SigningIdentity;
var Signer = idModule.Signer;
// CryptoSetting: https://fabric-sdk-node.github.io/global.html#CryptoSetting__anchor

//Sign
constructor(cryptoSuite, key) {
  this._cryptoSuite = cryptoSuite;
}
sign(digest, opts) {
		return this._cryptoSuite.sign(this._key, digest, opts);
}

// Client.js
crypto_suite = BaseClient.newCryptoSuite();
// BaseClient
static newCryptoSuite(setting) {
	return sdkUtils.newCryptoSuite(setting);
}

csImpl = useHSM ? this.getConfigSetting('crypto-suite-hsm') : this.getConfigSetting('crypto-suite-software');

var cryptoSuite = require(csImpl);
// the 'opts' argument to be passed or none at all
opts = (typeof setting === 'undefined') ? null : setting;

//opts Option is the form { lib: string, slot: number, pin: string }
return new cryptoSuite(keysize, hashAlgo, opts);
```
