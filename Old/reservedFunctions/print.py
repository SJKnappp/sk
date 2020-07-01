import config as con
from store import *

def FunPrint(words):
	if(words[1][0]!='"'):print("print() needs to start with a string with includes being compleated with % and a option")
	if(words[1][-1]!='"'):print("print() first element needs to be a string")

	out=""
	for y in range(1, len(words[1])-1):
		out+=words[1][y]
		if(words[1][y]=="%"): #will inplement later
			out=out[:-1]
	output(out)
	return

def output(foo):
	length=len(foo)
	if(con.printmsg==0):
		dataAdd("msg db '", 1, 1)
		dataAdd(foo, 0, 0)
		dataAdd("' ;print varible", 0, 0)
		con.printmsg=1
	else: con.text+="\n\tmov msg, '"+foo+"'"
	textAdd("mov eax, 4\n\tmov ebx, 1\n\tmov ecx, msg\n\tmov edx, "+str(length), 1, 1)
	textAdd("int 80h\n", 1, 1)