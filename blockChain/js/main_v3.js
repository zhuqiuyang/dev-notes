const SHA256 = require("crypto-js/sha256");

class Transaction {
  constructor(fromAddress, toAddress, amount) {
    this.fromAddress = fromAddress;
    this.toAddress = toAddress;
    this.amount = amount;
  }
}

class Block {
  constructor(timestamp, transactions, previousHash = "") {
    this.timestamp = timestamp;
    this.transactions = transactions;
    this.previousHash = previousHash;
    this.hash = this.calculateHash();
    // 随机数, 防止伪造, 与data数据无关
    this.nonce = 0;
  }
  // this block hash
  calculateHash() {
    return SHA256(
      this.index +
        this.previousHash +
        this.timestamp +
        JSON.stringify(this.data) +
        this.nonce
    ).toString();
  }

  mineBlock(diffculty) {
    while (this.hash.substring(0, diffculty) !== "0".repeat(diffculty)) {
      this.nonce++;
      this.hash = this.calculateHash();
    }

    console.log("BLOCK MINED: " + this.hash);
  }
}

class BlockChain {
  constructor() {
    this.chain = [this.createGenesisBlock()];
    this.diffculty = 2;
    this.pendingTransactions = [];
    this.miningReward = 100;
  }

  createGenesisBlock() {
    return new Block("01/01/2018", "Genesis", "0");
  }

  getLatestBlock() {
    return this.chain[this.chain.length - 1];
  }

  miningPendingTransactions(miningRewardAddress) {
    const block = new Block(Date.now(), this.pendingTransactions);
    block.mineBlock(this.diffculty);

    console.log("Block Successfully mined!");
    this.chain.push(block);

    // reset & send reward
    this.pendingTransactions = [
      new Transaction(null, miningRewardAddress, this.miningReward)
    ];
  }

  createTransaction(transaction) {
    this.pendingTransactions.push(transaction);
  }

  getBalanceAddress(address) {
    let balance = 0;

    for (const block of this.chain) {
      for (const trans of block.transactions) {
        if (trans.fromAddress === address) {
          balance -= trans.amount;
        } else if (toAddress === address) {
          balance += trans.amount;
        }
      }
    }

    return balance;
  }

  isChainValid() {
    for (let i = 1; i < this.chain.length; i++) {
      const currentBlock = this.chain[i];
      const previousBlock = this.chain[i - 1];

      if (currentBlock.hash !== currentBlock.calculateHash()) {
        return false;
      }

      if (currentBlock.previousHash !== previousBlock.hash) {
        return false;
      }

      return true;
    }
  }
}

const sCoin = new BlockChain();

sCoin.createTransaction(new Transaction("address1", "address2", 100));
sCoin.createTransaction(new Transaction("address2", "address", 50));

console.log("\n Starting mining...");
sCoin.miningPendingTransactions("AceAddress");

console.log('\nBalance of Ace: ', sCoin.getBalanceAddress('AceAddress'))
