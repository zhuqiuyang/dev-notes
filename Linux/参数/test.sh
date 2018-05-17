#!/bin/bash
# wait-for-postgres.sh

set -e

host="$1"
shift
cmd="$@"

echo "cmd is ${cmd}"

# exec $cmd