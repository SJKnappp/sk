from defFunction import *
from defvar import *
from checkExists import *
import config as con

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

	words=[]
	temp=""
	print(line)
	for x in range(0, len(line)):
		temp+=line[x]
		if(line[x]==' ' or line[x]==';'):
			temp=temp[:-1]
			if(temp!=''):
				words.append(temp) #adds the indvdual parts of the line 
	print(words)
	Type=type(words[0])
	start=0
	if(Type!=""):
		con.data+="\t"+Type + "\t" + Type[0:2] + " 0\n"
		start=1

	for x in range(start, len(words)):
		if(words[x]!="="): pass #checks for symbols then will run functions accordingly
		elif(words[x]!="=="): pass
		else:
			checkExists(words[x])

	#if(Type==""):
	#	print("not a varible")
	#else: var()
