```shell
sudo yum update

scp /Users/Ace/Downloads/go1.7.4.linux-amd64.tar.gz admin@10.57.17.67:/home/admin/

touch ./bash_profile
vim ./bash_profile

export GOROOT=/home/admin/go
export PATH=$PATH:/home/admin/go/bin
export GOPATH=/home/admin/goWorkSpace

yum install -y supervisord

vim /etc/supervisord.conf

nohup ./octopus-open > web.log 2>&1 &

scp -r /Users/Ace/Documents/go/src/octopus-open/client/dist/ admin@10.57.17.67:/home/admin/goWorkSpace/src/octopus-open/client/

scp -r /Users/Ace/Documents/go/src/octopus-open/ admin@10.57.17.67:/home/admin/goWorkSpace/src/octopus-open/
```
