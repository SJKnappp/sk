from defFunction import *
from defvar import *
from checkExists import *
from breakline import *
from function import *
from checkType import *
import config as con

#asses the line and decides what to do with it
def process(line):

	if(line[-1]=='{'):
		function(line)
		con.blockcount+=1 #counts for a check for exiting the program
		return

	if(line[-1]=='}'):
		con.blockcount-=1 
		if(con.inStart==0):	con.text+="\tret\n" 			#ret to previous function
		elif(con.blockcount==0):							#if count at 0 in start function place quit condition
			con.inStart=0
			con.text+="\tmov\teax, 1\n\tint\t0x80\n"
		con.text+="."+con.closeStack.pop()+":\n"			#adds a lable the assembly
		return
		

	words = breakline(line)									#breaks line to indvidual part

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
			if(words[x][0]=='='):
				if(Type!="fail"):
					holdequal=1
			if(holdequal==1):
				equals=words[x][0]
			if(define==1):
				vari=words[x][0]
				define=0

		elif(len(words[x])>1):
			requrments = checkExistsFunction(words[x][0])
			reversed = checkReservedFunction(words[x])
			if(len(reversed)!=0):
				coreFun(words[0])
			elif(len(requrments)==0):
				print("function not found")
				quit()
			elif(len(requrments)!=0):
				moveTo(words[x])
		
	if(Type!="fail"):
		exist = checkExists(vari)
		if(exist==0):
			if(holdequal==0):equals='0'
			typeCheck = checkType(words[0][0], int(equals))
			if(typeCheck==0):
				print("type not compatible with data")
				quit()
			con.data+="\t"+Type + "\t" + Type[0:2] + " " + equals +"\n"
			con.varibles.append([vari, words[0][0], Type[0:3]])
		else:
			print("function allready declared")
			quit()
	elif(vari!=""):
		exist = checkExists(vari)
		typeCheck = checkType(words[0][0], int(equals))
		if(typeCheck==0):
			print("type not compatible with data")
			quit()
		if(exists==0):
			print("varible does not exist")
			quit()
	return

