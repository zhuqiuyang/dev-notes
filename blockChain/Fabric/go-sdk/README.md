### sdk-e2e test

```sh
# 启动区块链服务
make dockerenv-stable-up

# 运行测试

TEST_CHANGED_ONLY=true FABRIC_CRYPTOCONFIG_VERSION=v1 FABRIC_SDKGO_CODELEVEL_VER=v1.1 FABRIC_SDKGO_CODELEVEL_TAG=stable TEST_LOCAL=true  test/scripts/integration.sh
```

### 区块链操作 API

- `config.FromFile`: 读取`yaml`配置.

  - `github.com/hyperledger/fabric-sdk-go/pkg/core/config`
  - 内部依赖`https://github.com/spf13/viper`: 解析不同格式配置文件.
  - yaml 字段:
    - `cryptoconfig`: msp 存储目录
    - `credentialStore`: user store

- `fabsdk.New()`:使用 yaml, 启动 sdk`:

  - `github.com/hyperledger/fabric-sdk-go/pkg/fabsdk`

- `ccPkg, err := packager.NewCCPackage(ccPath, goPath)`: 打包 CC
  - `packager "github.com/hyperledger/fabric-sdk-go/pkg/fab/ccpackager/gopackager"`
