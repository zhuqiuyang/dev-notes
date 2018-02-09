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
