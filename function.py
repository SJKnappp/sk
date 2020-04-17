import config as con

def moveTo(function):
	con.text+="\tjmp " + function[0] + "\n"
	return