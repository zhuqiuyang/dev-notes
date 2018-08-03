### sdk-e2e test

```sh
# 启动区块链服务
make dockerenv-stable-up

# 运行测试

TEST_CHANGED_ONLY=true FABRIC_CRYPTOCONFIG_VERSION=v1 FABRIC_SDKGO_CODELEVEL_VER=v1.1 FABRIC_SDKGO_CODELEVEL_TAG=stable TEST_LOCAL=true  test/scripts/integration.sh
```

### 签名测试

> `/Users/Ace/Documents/go/src/github.com/hyperledger/fabric-sdk-go/pkg/client/resmgmt/resmgmt.go`

```go
start := time.Now()

// var configSignatures []*common.ConfigSignature

// var arr [1000](*big.Int)
// for i := 0; i < 1000; i++ {
// configSignatures, err = rc.getConfigSignatures(req, chConfig)
// }
configSignatures, err := rc.getConfigSignatures(req, chConfig)
t := time.Now()
elapsed := t.Sub(start)
fmt.Println("Sign time:", elapsed)
```

### 备注

- `fabric-sdk-go`在`github.com/hyperledger/`目录下.

### 区块链操作 API

- `config.FromFile`: 读取`yaml`配置.

  - `fabric-sdk-go/pkg/core/config`
  - 内部依赖`https://github.com/spf13/viper`: 解析不同格式配置文件.
  - yaml 字段:
    - `cryptoconfig`: msp 存储目录
    - `credentialStore`: user store

- `fabsdk.New()`:使用 yaml, 启动 sdk`:

  - `fabric-sdk-go/pkg/fabsdk`

- Channel:

  - `JoinChannel`: 不指定参数, 默认所有 peer.
    > https://godoc.org/github.com/hyperledger/fabric-sdk-go/pkg/client/resmgmt#Client.JoinChannel
  - `SaveChannel`: 用于创建 Channel

- `ccPkg, err := packager.NewCCPackage(ccPath, goPath)`: 打包 CC
  - `packager "fabric-sdk-go/pkg/fab/ccpackager/gopackager"`

### Doc

- https://godoc.org/github.com/hyperledger/fabric-sdk-go/pkg/client/msp
- 升级 Channel: https://godoc.org/github.com/hyperledger/fabric-sdk-go/pkg/client/resmgmt#Client.UpgradeCC

### 存储

#### Enrollment 过程返回的

- `private key` is stored in the SDK crypto provider's key store
- `Ecert` is stored in the SDK's user store (state store).

#### 自定义用户存储

> 思路, 实现接口

- 参考`fabric-sdk-go/pkg/msp/memory_user_store.go`

### Client YAML 配置

> node, go SDK 所用配置格式一致(2018-07-10)
>
> `CRYPTOCONFIG_FIXTURES_PATH`在`fabric-sdk-go/test/fixtures/fabric/v1/crypto-config`目录

```yaml
- version
# 1. 定义这个 APP 属于哪个组织.
- client
  # Root of the MSP directories with keys and certs.(每个org的cryptoPath依赖root path)
  - cryptoconfig
  # client 使用的用户身份存储?
  - credentialStore
    # CryptoSuit 使用到的存储
    - cryptoStore
# 2. channel 的 peers, policy
- channels
# 3. 列出 network 中有哪些组织 ?
- organizations
# 4. network 所对应的 order
- orderers
# 5. 列出 所有需要使用的 peer
- peers
# 6. CA
- certificateAuthorities
```

- SDK 公钥存储: `client.credentialStore.path` (user store)
  - `fabric-sdk-go/pkg/msp/memory_key_store.go`: 可以在`StoreKey/GetKey`通过 channel, 发给外部
- SDK 私钥存储: `client.credentialStore.cryptoStore.path` (key 由 BCCSP 管理)
  - `fabric-sdk-go/pkg/msp/memory_user_store.go`

#### 名词

- credential: 及数字证书
  > https://hyperledger-fabric.readthedocs.io/en/latest/idemix.html?highlight=credential
