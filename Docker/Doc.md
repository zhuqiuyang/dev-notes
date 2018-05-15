## Get Start

### Part 1: Orientation and setup

#### Images and containers

* A container is launched by running an image.
* A **container** is a runtime instance of an image

```sh
# ls running container
docker ps
```

### Part 2: Containers

```sh
docker build -t friendlyhello .  # Create image using this directory's Dockerfile
docker run -p 4000:80 friendlyhello  # Run "friendlyname" mapping port 4000 to 80
docker run -d -p 4000:80 friendlyhello         # Same thing, but in detached mode
docker container ls                                # List all running containers
docker container ls -a             # List all containers, even those not running
docker container stop <hash>           # Gracefully stop the specified container
docker container kill <hash>         # Force shutdown of the specified container
docker container rm <hash>        # Remove specified container from this machine
docker container rm $(docker container ls -a -q)         # Remove all containers
docker image ls -a                             # List all images on this machine
docker image rm <image id>            # Remove specified image from this machine
docker image rm $(docker image ls -a -q)   # Remove all images from this machine
docker login             # Log in this CLI session using your Docker credentials
docker tag <image> username/repository:tag  # Tag <image> for upload to registry
docker push username/repository:tag            # Upload tagged image to registry
docker run username/repository:tag                   # Run image from a registry
```

### Part 3: Services

#### Intro

> In part 3, we scale our application and enable load-balancing. To do this, we must go one level up in the hierarchy of a distributed application: the service.

#### About services

在一个分布式应用中, different pieces of the app are called “services.”Eg: 一个 video site, 存储和解码是不同的`service`.

define, run, and scale services: 需要编写一个`docker-compose.yml`.

```yml
version: "3"
services:
  web:
    # replace username/repo:tag with your name and image details
    image: username/repo:tag
    deploy:
      replicas: 5
      resources:
        limits:
          cpus: "0.1"
          memory: 50M
      restart_policy:
        condition: on-failure
    ports:
      - "80:80"
    networks:
      - webnet
networks:
  webnet:
```

This `docker-compose.yml` file tells Docker to do the following:

* Pull the image

* Run 5 instances of that image as a service called `web`, limiting each one to use, at most, 10% of the CPU (across all cores), and 50MB of RAM.

* 立即重启 container if one fails.

* Map port 80 on the host to `web`’s port 80.

* Instruct `web`’s containers to `share` port 80 via a load-balanced network called `webnet`. (Internally, the containers themselves publish to `web`’s port 80 at an ephemeral port.)

* Define the `webnet` network with the default settings (which is a `load-balanced` `overlay` network).

#### Run your new load-balanced app

```sh
# 设置 swarm manager
docker swarm init

docker stack deploy -c docker-compose.yml getstartedlab
```

#### Scale the app

修改`replicas`字段, 重新执行`docker stack deploy -c docker-compose.yml getstartedlab`

* docker 支持 in-place update, 不需要 stack down first or kill any containers.

```sh
docker stack ls                                            # List stacks or apps
docker stack deploy -c <composefile> <appname>  # Run the specified Compose file
docker service ls                 # List running services associated with an app
docker service ps <service>                  # List tasks associated with an app
docker inspect <task or container>                   # Inspect task or container
docker container ls -q                                      # List container IDs
docker stack rm <appname>                             # Tear down an application
docker swarm leave --force      # Take down a single node swarm from the manager
```

### part 4