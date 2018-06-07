### 新建 git repo

```sh
git remote add origin git@gitlab.tongdun.cn:qiuyang.zhu/test.git
git push -u origin master
```

### 生成 ssh key

```sh
ssh-keygen
```

### get ssh-key

```sh
cat ~/.ssh/id_rsa.pub
```

### 删除远程 v1.3.0 分支

```sh
git push origin --delete v1.3.0
```

### 删除本地分支

```sh
git branch -d [branch_name]
```

### 查看远程所有 branch

```sh
git branch -a
```

### 获取 remote 最新信息

```sh
git fetch
```

### 切换到远程 origin/dev 分支,并与 local dev 分支对应起来.

```sh
git checkout -b dev origin/dev
```

### If you wish to set tracking information for this branch you can do so with:

```sh
git branch --set-upstream-to=origin/<branch> dev
```

### 缓存当前修改到 stash

```sh
git stash
git stash pop
```

### osxkeychain

> Keychain Access(钥匙串访问)存储 https 的 username, password

> git credential-osxkeychain push 时会申请读取 `钥匙串`中对应的内容
