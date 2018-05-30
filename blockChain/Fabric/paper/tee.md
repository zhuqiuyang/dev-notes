https://arxiv.org/abs/1805.08541

## Preface

起因: A smart contract on a blockchain cannot keep a secret because its data is replicated on all nodes in a network.

* 解决这个问题, 需要结合 bc 和 TEE(执行 app demand privacy, 需要解密数据?)

1.  paper 先 explore the `pitfalls` that arise from the combination of TEEs with blockchains

* TEE 易收到 roll back 的影响, 因为其无状态, 且共识未最终达成. (所以可以需要 roll back?)
* 而 POW 方式, 要求 smart contract 需要支持回滚?
* 所以, TEEs 只能与`共识已经完成`的 blockchain 相结合.

2.  介绍 architecture 和原型 for `smart-contract execution within Intel SGX technology for Hyperledger Fabric`

## 1. Introduction

SGX : It establishes trusted execution contexts called enclaves on a CPU

* isolate data and programs

举例: Imagine an auction of a digital item on a blockchain. In sealed-bid auction designs (密盒拍卖)

* in bc, auctioneer(拍卖商)就是 smart contract,
* 账本存储了 encrypted bids(bidder 需要在最终 evaluation 时 verify 他们投出的 bids)

running the `auction’s code` within an SGX enclave

* the bids are encrypted, the `key` to decrypt them resides only inside the enclave
* the `smart contract` controls operations with the key.

> The `bidders` commit their `encrypted bids` to the blockchain and the `enclave` `decrypts` them for determining the winner.

问题是, 可能有信息 leak 的风险, 一个恶意的 node can manipulate the operation invocation order.

integrity violation(违反),

POW 不是从 TEE 中受益

If the blockchain nodes hosting TEEs can access the final blockchain state in a trusted way, on the other hand, then such rollbacks can be prevented.

Fabric 的 `consensus` whose outputs are always final, 所以 rollback attack

* auction 的 app 执行吞吐是 unprotected 实现方式的 0.8~0.9 倍, 可接受.

后续:
Section 2: 介绍公链不能与 TEE 结合
Section 3: SGX & Fabric
Section 4: 介绍 system model
Section 5: execute app on fabric and SGX
Section 6: Security 评估
Section 7: 性能
Section 8: Review
Section 9: Conclude

#### 3.2 Trusted execution with Intel SGX

SGX enables Fabric peers to execute chaincode in a trusted execution context, also called enclave.

* Enclave protection and attestation:

  * SGX 规定只有`Genuine`(纯: code 没有被篡改; 按开发者 intended 运行)app 可以运行在其中
  * `mrenclave`: a cryptographic hash, code 和 data 首次 load into enclave, CPU 计算产生.

* During runtime, an `enclave` 可被视为第三方(fabric client or peer)

  * remote attestation(远程认证: )

* Enclave state and data sealing
