from defFunction import *
import config as con

def process(line):

	if(line[-1]=='{'):
		function(line)
		return

	if(line[-1]=='}'):
		if(con.inStart==0):	con.text+="\tret\n"
		else:
			con.inStart=1
			con.data+="mov\tedx, 1\n\tint\t0x80"

	Type=""
	for x in range(0, len(line)):
		Type+=line[x]
		if(line[x]==' '):
			Type=Type[:-1]
			break

	if(Type==""):
		print("not a varible")
	#else: defvar()
