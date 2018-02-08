# supervisord 和 supervisorctl 指令必须要在同一个包含conf配置文件夹下执行才有效。

# conf 中使用环境变量 eg:
pidfile= %(ENV_GOPATH)s/supervisord.pid ; (supervisord pidfile;default supervisord.pid)

# supervisorctl cmd
shutdown
reload -c
start app_name
restart all
