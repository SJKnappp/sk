import config as con

def moveTo(function):
	con.text+="\tjmp _" + function[0] + "\n"
	return