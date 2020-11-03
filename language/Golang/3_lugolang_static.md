![](quiver-image-url/AE60A0D712BFF9020973E586FBE87577.jpg)

1\. FS.Root 是空的情况,默认使用相对路径.

2\. FS 默认从file取cache, 成功 则不用file path.

3\. 修改New 为接受变参.

FS默认配置:
- Compress 启用
- ROOT 默认基于GOPATH.
- ByteRange不开
- GenerateIndex 默认不开.
