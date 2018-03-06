### 4. Introduction

#### 4.1 What is Blockchain?

For now, it’s enough to think of a `blockchain` as a `shared, replicated transaction system` which is updated via `smart contracts` and kept consistently synchronized through a collaborative process called `consensus`.

#### 4.3 What is Fabric?

> a project with Hyperledger.

特点: private, permissioned.
the `members` of a Hyperledger Fabric network `enroll(注册)` through a Membership Service Provider (MSP).

##### 4.3.1 Shared Ledger

ledger 组成: `world state` 和 `transaction log`.

##### 4.3.2 Smart Contracts

有`chaincode`编写, 被 application 调用.

> chaincode 目前支持 go, node 编写.

##### 4.3.3 privacy

通过 channel, create `separate ledger`

##### 4.3.4 Consensus(共识)

PBFT (Practical Byzantine Fault Tolerance)

Later, 学习 SOLO, Kafka, and will soon extend to SBFT (Simplified Byzantine Fault Tolerance).
