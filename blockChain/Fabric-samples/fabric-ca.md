> https://github.com/hyperledger/fabric-samples/tree/release-1.1/fabric-ca

* `scripts/env.sh`define the names and topology of this sample
* `start.sh`: first builds the `docker-compose.yml` file (by invoking the `makeDocker.sh` script) and then starts the docker containers.
  * `data` 文件夹作为 volume 在所有 container 见共享, 真实场景可能不需要:
    * a) 收集 log
    * b) 启动顺序控制(eg: ica 依赖 rootca)
    * c) to access bootstrap `certificates` required by clients to connect over TLS.
* `docker-compose.yml`中启动顺序:
  * 1)rca(root CA): one for each org
  * 2)ica(intermediate CA):
  * 3)`setup` (`setup-fabric.sh`)
    * `registers identities` with the ica
    * generates the genesis block,
    * other artifacts needed to setup the blockchain network
      > admin ECert `abac.init`属性为`true`
  * 4)order and peer start
  * 5)`run-fabric.sh` for test
    * create channel
    * peers join channel
    * cc install, instantiated, query/invoke
