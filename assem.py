from defFunction import *
from defvar import *
from checkExists import *
from breakline import *
from function import *
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
			con.text+="\tmov\teax, 1\n\tint\t0x80\n"
		con.text+="."+con.closeStack.pop()+":\n"
		return
		

	words = breakline(line)
	print(words)

	Type=type(words[0][0])
	start=0
	define=0
	if(Type!="fail"):
		start=1
		define=1

	exists = 0
	equals=""
	vari=""
	holdequal=0
	for x in range(start, len(words)):
	

		if(len(words[x])==1): 
			if(words[x]=="="):
				if(Type!="fail"):
					holdequal=1
			if(holdequal==1):
				equals=words[x]
			if(define==1):
				vari=words[x]
				define=0

		elif(len(words[x])>1):
			requrments = checkExistsFunction(words[x][0])
			if(len(requrments)==0):
				print("function not found")
				quit()
			moveTo(words[x])
		
	if(Type!="fail"):
		exist = checkExists(vari[0])
		if(exist==0):
			if(holdequal==1): con.data+="\t"+Type + "\t" + Type[0:2] + " " + equals +"\n"
			else: con.data+="\t"+Type + "\t" + Type[0:2] + " 0\n"
			con.varibles.append([vari[0], Type[0:2], Type[0:3]])
		else:
			print("function allready declared")
			quit()
	return
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
