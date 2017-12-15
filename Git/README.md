### 生成ssh key
ssh-keygen

### get ssh-key
cat ~/.ssh/id_rsa.pub

### 删除远程v1.3.0分支
git push origin --delete v1.3.0

### 删除本地分支
git branch -d [branch_name]

### 查看远程所有branch
git branch -a

### 获取remote最新信息
git fetch

### 切换到远程origin/dev分支,并与local dev分支对应起来.
git checkout -b dev origin/dev

### If you wish to set tracking information for this branch you can do so with:
git branch --set-upstream-to=origin/<branch> dev

### 缓存当前修改到stash
git stash
git stash pop

### osxkeychain
> Keychain Access(钥匙串访问)存储https的 username, password
git credential-osxkeychain push时会申请读取 `钥匙串`中对应的内容