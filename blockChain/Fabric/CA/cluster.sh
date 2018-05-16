docker network create -d overlay ca-network
# cp mysql配置到虚拟机
docker-machine scp -r mysql.conf/ myvm1:/home/docker/


# DB

docker service create \
  --name db \
  --network ca-network \
  --env MYSQL_DATABASE=fabric_ca \
  --env MYSQL_ROOT_PASSWORD=rootpw \
  --replicas 1 \
  --publish 3306:3306 \
  --mount type=bind,source=/home/docker/mysql.conf,destination=/etc/mysql/mysql.conf.d \
  mysql:5.7
  # --env MYSQL_USER=root \
  # --env MYSQL_PASSWORD=rootpw \


# Root CA

docker service create \
  --name root-ca \
  --network ca-network \
  --env "FABRIC_CA_HOME=$HOME/fabric-ca/server" \
  --replicas 1 \
  --publish 7054:7054 \
  hyperledger/fabric-ca:x86_64-1.1.0 \
  fabric-ca-server start -b admin:adminpw --db.type mysql --db.datasource "root:rootpw@tcp(db:3306)/root_ca?parseTime=true"

# 中间CA

docker service create \ 
  --name imd-ca \
  --network ca-network \
  --replicas 5 \
  --env "FABRIC_CA_HOME=$HOME/fabric-ca/server" \
  --publish 7055:7054 \
  hyperledger/fabric-ca:x86_64-1.1.0
  fabric-ca-server start -b admin:adminpw --db.type mysql --db.datasource "root:rootpw@tcp(db:3306)/imd_ca?parseTime=true"

# Test

docker service create \
  --name my-nginx \
  --network ca-network \
  --replicas 1 \
  --publish 80:80 \
  nginx:latest