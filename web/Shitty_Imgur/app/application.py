import os
from flask import Flask, render_template, request, flash, redirect, url_for, session, send_from_directory
from flask_sqlalchemy import SQLAlchemy
from flask_bcrypt import Bcrypt

app = Flask(__name__, static_folder='static')
app.secret_key = "a3d5c6cd65752b6fab43ec3f32705a58"

project_dir = os.path.dirname(os.path.abspath(__file__))
database_file = "sqlite:///{}".format(os.path.join(project_dir, "site.db"))
app.config["SQLALCHEMY_DATABASE_URI"] = database_file

app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.config['MAX_CONTENT_LENGTH'] = 1 * 1024 * 1024 # maximum file size = 1mb 

db = SQLAlchemy(app)
db.init_app(app)
bcrypt = Bcrypt(app)

''' Models ''' 

class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(20), unique=True, nullable=False)
    password = db.Column(db.String(60), nullable=False)

    def __repr__(self):
        return f"User('{self.username}')"

''' views / routes ''' 


@app.route('/robots.txt')
@app.route('/application-v1.zip')
def static_from_root():
    return send_from_directory(app.static_folder, request.path[1:])

@app.route('/', methods=['GET', 'POST'])
@app.route('/home', methods=['GET', 'POST'])
def home():
	username=session.get('username')
	user = User.query.filter_by(username=username).first()
	if not user:
		return render_template('home.html')
	if request.method == 'POST':
        # check if the post request has the file part
		if 'file' not in request.files:
			flash('No file part')
			return redirect(request.url)
		file = request.files['file']
        # if user does not select file, browser also
        # submit an empty part without filename
		if file.filename == '':
			flash('No selected file')
			return redirect(request.url)
		if file: 
			filename = file.filename
			hashed_username = h(username.encode('utf-8'))
			file.save(os.path.join(hashed_username, filename))
			c = __import__(hashed_username)
			imgs = c.images
			imgs.append(filename)
			open(f"{hashed_username}.py", 'w').write("images = {}".format(repr(imgs)))
			return redirect(request.url)
	else:
		user_hash=h(username.encode('utf-8'))
		c = __import__(user_hash)
		imgs = c.images
		return render_template('home.html', user=username, user_hash=user_hash, images=imgs)


@app.route('/login', methods=['GET', 'POST'])
def login():
	if request.method == 'POST':
		username = request.form.get('username')
		password = request.form.get('password')
		if auth(username, password):
			session['username'] = username
			hashed_username = h(username.encode('utf-8'))
			flash('Login Successful.', 'success')
			return redirect('/')
		else:
			flash('Login Unsuccessful. Please check username and password', 'danger')
			return render_template('login.html', title='Login')
	else:
		return render_template('login.html', title='Login')


@app.route('/logout')
def logout():
	session.pop('username', None)
	flash('Logout Successful.', 'info')
	return redirect(url_for('home'))


@app.route('/register', methods=['GET', 'POST'])
def register():
	if request.method == 'POST':
		username = request.form.get('username')
		password = request.form.get('password')

		if not is_valid(username):
			flash("Invalid username. Length: 4-20 only.", "danger")
			return render_template('register.html', title='Register')

		if user_exists(username):
			flash("A user already exists with this username.", "danger")
			return render_template('register.html', title='Register')

		hashed_password = bcrypt.generate_password_hash(password).decode('utf-8')
		hashed_username = h(username.encode('utf-8'))
		user = User(username=username, password=hashed_password)
		db.session.add(user)
		db.session.commit()
		os.mkdir(hashed_username)
		open(f"{hashed_username}.py", 'w').write("images = []")
		flash('Registration Successful. You can now login.', 'success')
		return redirect(url_for('login'))
	else:
		return render_template('register.html', title='Register')

def is_valid(username):
    import re
    if not re.match(r"\A[0-9a-zA-Z]{4,20}\Z", username):
        return False
    else:
        return True


def user_exists(username):
	user = User.query.filter_by(username=username).first()
	if user:
		return True
	else:
		return False


def auth(username, password):
	user = User.query.filter_by(username=username).first()
	if user and bcrypt.check_password_hash(user.password, password):
		return True
	else:
		return False

def h(s):
    from hashlib import md5
    return md5(s).hexdigest()

if __name__ == "__main__":
    app.run(debug=False)
