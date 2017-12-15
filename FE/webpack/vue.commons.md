### basic

webpack的三个概念：模块（module）、入口文件（entry）、分块（chunk）。

其中，module指各种资源文件，如js、css、图片、svg、scss、less等等，一切资源皆被当做模块。

webpack编译输出的文件包括以下2种：

- entry：入口，可以是一个或者多个资源合并而成，由html通过script标签引入
- chunk：被entry所依赖的额外的代码块，同样可以包含一个或者多个文件

### [CommonsChunkPlugin](https://webpack.js.org/plugins/commons-chunk-plugin/#extra-async-commons-chunk)

- name: 抽离出的chunk的文件name
- chunks: Select the source chunks by chunk names. The chunk must be a child of the commons chunk.