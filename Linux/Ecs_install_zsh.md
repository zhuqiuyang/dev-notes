yum -y install zsh
yum -y install git
#安装oh-my-zsh,会默认安装到当前用户的home目录下
sh -c "$(curl -fsSL https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
#查看本机shells
cat /etc/shells
#切换shell (Debian)
chsh -s /usr/bin/zsh

vim .zshrc
