#!/bin/bash
# wait-for-mysql.sh

set -e

host=`echo $1 | awk -F: '{print $1}'`
port=`echo $1 | awk -F: '{print $2}'`
shift
cmd="$@"

echo "${host} , ${port}, cmd is ${cmd}"

# until mysql -h "$host" -u "root" -p "rootpw"; do
until nc -z $host $port; do
  >&2 echo "mysql is unavailable - sleeping"
  sleep 2
done

sleep 3
>&2 echo "mysql is up - executing command"
exec $cmd

$(echo {$foo/:/ } | nc -z)
$(echo 'db 3306' | nc -z)