from defFunction import *
from defvar import *
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
	if(Type!=""):
		con.data+="\t"+Type + "\t" + Type[0:2] + ", 0\n"

	#if(Type==""):
	#	print("not a varible")
	#else: var()
