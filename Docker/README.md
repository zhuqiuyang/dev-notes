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

#### overlay 网络使用

> 前提: swarm cluster

方式一: `docker stack deploy -c <compose-file>`

* 优势: 方便(一键启动很多 service)
* 缺点: 不支持`depends_on`, `links`

方式二: `docker network creat -d overlay <network-name>`, 再`docker service create --network <net-work> <image>`

* 优势: 灵活
* 缺点: 不支持 file 配置, 多 service 启动都需要手动 command.
