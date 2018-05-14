### Reference

1. [阮老师-SSH原理及应用](http://www.ruanyifeng.com/blog/2011/12/ssh_remote_login.html)
2. [First 5min on a server](https://plusbryan.com/my-first-5-minutes-on-a-server-or-essential-security-for-linux-servers)
3. [First ten min on a server](http://www.codelitt.com/blog/my-first-10-minutes-on-a-server-primer-for-securing-ubuntu/)

### 1.首次root登陆,创建用户并启动ssh服务

```shell
useradd power
mkdir /home/power
mkdir /home/power/.ssh
chmod 700 /home/power/.ssh
```
- 手动或者上传local公钥
```shell
vim /home/power/.ssh/authorized_keys

chmod 400 /home/power/.ssh/authorized_keys
chown power:power /home/power -R
```

### 2.创建新用户
```shell
apt-get/yum install sudo
##visudo  会默认打开进行编辑,debian下可以执行
vim /etc/sudoers
#sudoers中 用户名 和ALL 必须空4格空格.
#或者
visudo

root    ALL=(ALL) ALL
power  ALL=(ALL) ALL
## wq! (强制保存)

#Vagrant 创建用户
sudo adduser power --ingroup sudo
```

### 3.sshd(服务端)配置
```shell
vim /etc/ssh/sshd_config

PermitRootLogin no
PasswordAuthentication no
AllowUsers power@(your-ip)
```

### 4.ssh服务开启、重启、开机自启
```shell
#centOS7下
systemctl start sshd.service
systemctl restart sshd.service
systemctl enable sshd.service

#Debian8下
service ssh restart
```

### 5.本地mac,生成并上传ssh公钥
```shell
ssh-keygen
brew install ssh-copy-id
ssh-copy-id user@host
```
