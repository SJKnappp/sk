from defFunction import *
from defvar import *
from checkExists import *
from breakline import *
import config as con

#asses the line and decides what to do with it
def process(line):

	if(line[-1]=='{'):
		function(line)
		return

	if(line[-1]=='}'):
		if(con.inStart==0):	con.text+="\tret\n"
		else:
			con.inStart=1
			con.text+="mov\tedx, 1\n\tint\t0x80"
		return

	words = breakline(line)

	Type=type(words[0])
	start=0
	if(Type!="fail"):
		con.data+="\t"+Type + "\t" + Type[0:2] + " 0\n"
		start=1

	exists = 0
	for x in range(start, len(words)):
	

		if(len(words[x])==1): pass
		elif(len(words[x])>1):
			requrments = checkExistsFunction(words[x][0])
			if(len(requrments)==0):
				print("function not found")
				quit()
			for y in range(1, len(words[x])):
				words[x]

		


		#print(words[x])
		#if(words[x]!="="): pass #checks for symbols then will run functions accordingly
		#elif(words[x]!="=="): pass
		#else:
		#	exists = checkExists(words[x])
		#	if(exists==0):
		#		print("function not found")
		#		quit()
		#	else: pass
	#if(Type==""):
	#	print("not a varible")
	#else: var()
