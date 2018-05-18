### docker exec

> Run a command in a running container
>
> https://docs.docker.com/engine/reference/commandline/exec/#usage

```sh
# 进入指定容器bash 交互
docker exec -it 2c1a3842cecb bash
```

### Docker CLI

> https://docs.docker.com/engine/reference/commandline/container_ls/#description

* `docker container ls -q`: `--quite, -q` (只 show numberIDs)

#### 查看

```sh
docker node ls  # list node (swarm manager)
docker service ls   # 查看service

## 常用 (查看某个service下的task 运行在哪些host上)
docker service ps <service>                  # List tasks associated with an app

docker container ls
docker container inspect <container-id>
```

#### remove

```sh
docker service rm $(docker service ls -q)
```

#### overlay 网络使用

> 前提: swarm cluster

方式一: `docker stack deploy -c <compose-file>`

* 优势: 方便(一键启动很多 service)
* 缺点: 不支持`depends_on`, `links`

方式二: `docker network creat -d overlay <network-name>`, 再`docker service create --network <net-work> <image>`

* 优势: 灵活
* 缺点: 不支持 file 配置, 多 service 启动都需要手动 command.

#### Service 网络连接

swarm 默认`ingress`网络 without `--attachable`, 所以只有`swarm services`可以使用.

* 创建时`--attachable`, 则 standlone `container`可以加入.

swarm 默认网络, 默认无法与用户创建的`overlay`网络通信.

#### 使用环境变量

You can use a `$$` 当你的配置需要使用`$` Literal.

```sh
web:
  build: .
  command: "$$VAR_NOT_INTERPOLATED_BY_COMPOSE"
```
