const SHA256 = require("crypto-js/sha256");

class Block {
  constructor(index, timestamp, data, previousHash = "") {
    this.index = index;
    this.timestamp = timestamp;
    this.data = data;
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
  }

  createGenesisBlock() {
    return new Block(0, "01/01/2018", "Genesis", "0");
  }

  getLatestBlock() {
    return this.chain[this.chain.length - 1];
  }

  addBlock(newBlock) {
    newBlock.previousHash = this.getLatestBlock().hash;
    // newBlock.hash = newBlock.calculateHash();
    newBlock.mineBlock(this.diffculty);
    this.chain.push(newBlock);
  }

  isChainValid() {
    for (const i = 1; i < this.chain.length; i++) {
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

console.log("Mining Block 1 ...");
sCoin.addBlock(new Block(1, "03/03/2018", { amount: 4 }));

console.log("Mining Block 2 ...");
sCoin.addBlock(new Block(2, "28/07/2020", { amount: 10 }));

console.log("Is BlockChain Valid: ", sCoin.isChainValid());
