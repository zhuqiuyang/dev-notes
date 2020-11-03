from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
        return 'Hello, World!'


@app.route('/nihao')
def hello_world_2():
        return 'Hello, World! And NiHao!'
