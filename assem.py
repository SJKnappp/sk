from defFunction import *
import config as con

def process(line):

	if(line[-1]=='{'):
		function(line)
		return

	if(line[-1]=='}'):
		con.text+="\tret\n"

	Type=""
	for x in range(0, len(line)):
		Type+=line[x]
		if(line[x]==' '):
			Type=Type[:-1]
			break

	if(Type==""):
		print("not a varible")
	#else: defvar()
