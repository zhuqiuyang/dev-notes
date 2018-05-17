#!/bin/bash
# wait-for-mysql.sh

set -e

host="$1"
shift
cmd="$@"

echo "${host} , cmd is ${cmd}"

# until mysql -h "$host" -u "root" -p "rootpw"; do
until nc -z db 3306; do
  >&2 echo "mysql is unavailable - sleeping"
  sleep 2
done

sleep 3
>&2 echo "mysql is up - executing command"
exec $cmd