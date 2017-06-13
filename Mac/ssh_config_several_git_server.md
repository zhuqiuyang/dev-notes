1. 在 `home/.ssh` 文件加下根据不同web生成对应key
2. 在 `home/.ssh` 中配置 `config`文件(其中Host做提示使用)

```shell
#gitlab
Host gitlab
	HostName gitlab.fraudmetrix.cn
	IdentityFile ~/.ssh/id_rsa

#github
Host github
	HostName www.github.com
	IdentityFile ~/.ssh/github_rsa

#AliyunCode
Host AliyunCode
	HostName code.aliyun.com
	User ACE
	IdentityFile ~/.ssh/AliyunCode_id_rsa

#ECS
Host AliyunEcs
	HostName saber.xin
	IdentityFile ~/.ssh/id_rsa
```
