### 2. Action

注意:
配置加速器时, 要把 debug 等选项设为 false

```json
{
  "debug": false,
  "registry-mirrors": ["https://gs4gsjhk.mirror.aliyuncs.com"],
  "experimental": false
}
```

```sh
# run一个镜像, 并运行 echo 命令
docker run ubuntu echo hello docker.

# 本地 nginx服务80 -> 8080端口 , -d daemon 执行
docker run -d -p 8080:80 --name webserver nginx

# 在Host 和 container 之间拷贝文件
docker cp file 78as7fsad://usr/share/nginx/html

# stop
docker stop id

# 再次启动, 显示初始的网页
docker commit -m 'fun' id

# 展示image列表
docker images

# rm image
docker rmi id

# 列出所有容器, 无 -a 只显示正在运行.
docker ps -a
# 清除容器
docker rm id1 id2
```

### 3. Dockerfile

#### 3.1 简单

> 通过 dockerfile 来创建镜像

```sh
# 基础镜像
FROM alpine:latest

# 维护者
MAINTAINER Ace

# 命令
CMD echo 'hello docker'
```

* alpine 专门针对 docker 做的极小的 linux 环境.

```sh
# -t是tag, . 是指当前文件下的所有文件
docker build -t hello_docker .

docker run hello_docker
```

#### 3.2 实战

> dockerfile1/2

#### 3.3 镜像分层

* dockerfile 每一行都产生一个新层
* IMAGE 是 RO(只读的)
* IMAGE 运行时产生的容器层是 RW(可读写的)

分层的好处:

* IMAGE 之间, 层共享, 可减小存储压力.

#### 4.1 Volume 介绍

> 提供**独立**于容器之外的**持久化**存储.

能被容器之间共享, eg, DB 存储.

#### 4.2 volume 操作

eg, 通过`nignx -v`挂载一个卷

```sh
docker run -d --name nginx -v /usr/share/nginx/html nginx

docker inspect nginx
```

观察: `Mounts.Source AND Destination`: 把 Host 主机的路径, 挂载到容器的某个地址.

> 提示: 由于 Mac 是先运行一个 Linux 的 vm, 然后在其内部运行 docker, 所以要先进入 vm 才可以.

```sh
screen ~/Library/Containers/com.docker.docker/Data/com.docker.driver.amd64-linux/tty
# tty 简单理解成 terminal
```

修改 VM volume 中的文件, 然后进入容器观察:

```sh
docker exec -it nginx /bin/bash
```

##### 挂载一个本地目录到容器

```sh
docker run -p 80:80 -d -v $PWD/html:/usr/share/nginx/html nginx
```

便于开发:

* 直接 Host 内修改, 即可映射到容器.

##### 挂载一个已有数据的容器, 并将它当做`Volume`挂载到其他容器.
