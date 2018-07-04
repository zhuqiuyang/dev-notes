### sdk-e2e test

```sh
# 启动区块链服务
make dockerenv-stable-up

# 运行测试

TEST_CHANGED_ONLY=true FABRIC_CRYPTOCONFIG_VERSION=v1 FABRIC_SDKGO_CODELEVEL_VER=v1.1 FABRIC_SDKGO_CODELEVEL_TAG=stable TEST_LOCAL=true  test/scripts/integration.sh
```
