from flask import Flask, jsonify, request, Response, render_template
from GhostLegLib import makeNameList
app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/people', methods=['GET','POST'])
def people():
    return render_template('people.html')

@app.route('/naming', methods=['GET','POST'])
def naming():
    N = int(request.form['people'])
    
    list = makeNameList(N)
    print(list)
    return render_template('naming.html', N=N, list=list)


@app.route('/result', methods=['GET','POST'])
def result():
    return render_template('result.html')
    
if __name__== "__main__":
    app.run(host='0.0.0.0',debug=True)
