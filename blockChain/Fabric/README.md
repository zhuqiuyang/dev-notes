## Key Concepts

> 个人理解: Endorser(公证节点)

### Identity

* principal(主角): like userIDs or groupIDs.

Public Key Infrastructure (PKI)两大组成:

* Certificate Authorities who issue digital certificates to parties
* Certificate Revocation List (CRL) 包含 a reference for the certificates .

There are four key elements to PKI:

* Digital Certificates
* Public and Private Keys
* Certificate Authorities
* Certificate Revocation Lists

#### Root CAs, Intermediate CAs and Chains of Trust

建立了一个认证的 chain. (减少 root ca 的暴露)

#### Fabric CA

**fabric-ca** is a private root CA provider capable of managing digital identities of Fabric participants that have the form of X.509 certificates.

#### Identity 总结

* `PKI` 提供 verifiable identities through a chain of trust
* the `next step` is to see how these `identities` can be used to represent the `trusted members` of a blockchain network.
* That’s where a Membership Service Provider (`MSP`) comes into play – it identifies the parties who are the members of a given organization in the blockchain network.

### Membership

**MSP identifies which Root CAs and Intermediate CAs are trusted to define the members of a trust domain, e.g., an organization**

* 一种方式是列出其(org)members
* or by identifying which `CAs` are `authorized` to `issue` valid identities for their members

还包括:

* 识别 acotr 在指定 network 中的 role`identify specific roles an actor might play`
* 设置访问特权(eg.channel admins, readers.)
* MSP 对 all channel 是公开的

#### Mapping MSPs to Organizations

What’s most important about organizations (or orgs) is that they manage their members under a single MSP.

此处`org`概念和 X.509 中`org`不同.

#### Local and Channel MSPs

* **`Local MSPs` defined for nodes (peer or orderer) and users (administrators that use the CLI or client applications that use the SDK).**
  Every node and user must have a local MSP defined, as it defines who has administrative or participatory rights at that level and outside the context of a channel (who the administrators of a peer’s organization, for example).

* **`channel MSPs` define administrative and participatory rights at the channel level. Every organization participating in a channel must have an MSP defined for it.**

* **Local MSPs are only defined on the file system of the node or user to which they apply.**
* **channel MSPs are available to all nodes in the channel**
* **a channel MSP is instantiated on the file system of every node in the channel and kept synchronized via consensus.**

#### MSP Levels

* **MSPs at a higher level relating to network administration concerns**
* **while MSPs at a lower level handle identity for the administration of private resources.**

* Network MSP
* Channel MSP
* Peer MSP
* Orderer MSP

### Peer

> Endorser & Commiter

ledger 和 chaincode 都在 peer 上都有一份实例. 访问 ledger 的时候, 最好通过 chaincode 编写的程序(smart contract).

`smart contracts` with a technology concept it calls `chaincode` – simply a piece of code that accesses the ledger.

#### Peers and Channels

Conceptually you can think of channels as being similar to groups of friends.

可以把`channel` 看成 logical structure that is formed by a collection of physical peers.

#### Peers and Organizations

* Blockchain networks are administered by 多个 organization.

* Peers 分属不同的 organization.

* Blockchain network literally 上说是不存在的, 如果没有 organization 贡献 Resources.

* 单个 Organization 的离开或者加入并不影响 network 的存在. This is at the heart of what it means for a network to be decentralized.

#### Peers and Identity

a peer can only be owned by a single organization, and is therefore associated with a single MSP.

#### Peers and Orderers

应用 update ledger 需要 3 个 phase, which ensures that all the peers in a blockchain network keep their ledgers consistent with each other.

1.  applications work with a subset of endorsing peers, each of which provide an endorsement(sign, 公证) of the proposed ledger update to the application, but do not apply the proposed update to their copy of the ledger.

2.  these separate endorsements are collected together as transactions and packaged into blocks.

3.  these blocks are distributed back to every peer where each transaction is validated before being applied to that peer’s copy of the ledger.

`orderer` nodes are central to this process.

##### Phase 1: Proposal

This `endorsement` 可用于之后证明是此 peer 签名的. eg: `if peer P1 is owned by organization Org1, endorsement E1 corresponds to a digital proof that “Transaction T1 response R1 on ledger L1 has been provided by Org1’s peer P1!”.`

##### Phase 2: Packaging

`orderers` 的工作 simple but vital:

* collecting proposed transaction updates
* ordering them
* packaging them into blocks
* ready for distribution

注意:

* package 顺序是任意的, 并不是按照接收的顺序.
* `strick mode`: same transaction 不能 package 到不同 block

##### Phase 3: Validation

peer 接收到 order 分发的新的 block, 会先对其中每一条 transaction 进行 validate:

* 成功(`endorsed by all relevant organizations`), 则 attemp apply to ledger
  * perform `ledger consistency check` to `verify` ledger 当前 state 和`proposed update` 产生时的 state 一致.
* 失败, 保留用做 audit(审计), 但不写入.

其他:

* peer 除了直连 order, 还可以通过`gossip`协议通过其他 peer 进行 block 同步.
* `chaincodes`只在 endorsing nodes 可用(phase-1)
  > This is often helpful as it keeps the logic of the chaincode confidential to endorsing organizations.

##### Orderers and Consensus

This entire transaction workflow process is called `consensus`.

### Ledger (1.1 增加)

### Chaincode for Operators

Chaincode runs in a secured Docker `container` isolated from the endorsing peer process. Chaincode `initializes` and manages ledger state through transactions submitted by applications.

#### lifecircle

`package`, `install`, `instantiate`, and `upgrade`. In a future release, we are considering adding `stop` and `start`
`invoke`

### Transaction Flow

## Operations Guides

### Endorsement policies

`Endorsement policies` are used to instruct a peer on how to decide whether a transaction is properly `endorsed`. When a peer receives a transaction, it `invokes` the VSCC (Validation System Chaincode) associated with the transaction’s Chaincode as part of the transaction validation flow to `determine the validity of the transaction`.

## Architectur Reference

### Architecture Explained

#### 2.2. The endorsing peer simulates a transaction and produces an endorsement signature

在 1.0 架构中，一个 transaction 包括如下信息：

```
[ledger] [channel], proposal:[chaincode, ] endorsement:[proposal hash, simulation result, signature]
```

* `endorsements`: proposal hash, simulation result, signature

#### 3. Endorsement policies

> policy 规定了 transaction 执行公证所需`endorser`的最小节点数.