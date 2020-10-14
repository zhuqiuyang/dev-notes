### flask


ˋˋˋsh
# 1. install python3 & vitual-venv

sudo apt install python3 python3-venv

# 2. create project

mkdir 1_flast
cd 1_flask

# 3. create venv dir in this project dir.
# call venv, create venv dir. (use python3)
python3 -m venv venv

# 4. active
source venv/bin/activate

# 5. run app
flask run

# 6. test
nc localhost 5000
>GET / HTTP/1.1
>Host: localhost:5000

<HTTP/1.0 200 OK
ˋˋˋ
