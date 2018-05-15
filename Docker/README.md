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
docker node ls  # list node
docker stack ps getstartedlab   # List the tasks in the stack
docker service ls   # 查看service
docker service ps <service>  # view tasks for a service.
```
