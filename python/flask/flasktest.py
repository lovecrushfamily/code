
import flask

app = flask.Flask(__name__)

@app.route("/")
def index():
    return "Love crush was , how the fuck react js icon was in the titile!"

@app.route("/api/<name>", methods=["GET"])
def get_api(name):
    cookies = flask.request.cookies
    res = flask.make_response("Hello" + name)
    res.headers['Content-type'] = 'text'
    res.set_cookie('subscribe', 'true')
    return res

@app.route("/ninja/<key>", methods=['POST'])
def template(key):
    return flask.render_template("index.html", key=key)

@app.route("/image")
def send_file():
    return flask.send_file('image.png')


if __name__ == "__main__":
    app.run("0.0.0.0", port=3000, debug=True)