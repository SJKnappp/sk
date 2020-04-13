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
	tempN="" #varible name
	tempA=[] #varible data
	inFunc=0
	count=0
	for x in range(0, len(line)):
		tempN+=line[x]
		if(line[x]==' ' or line[x]==';'):
			count+=1
			tempN=tempN[:-1]
			if(tempN!=''):
				words.append(tempN) #adds the indvdual parts of the line 
		if(line[x]=='='):

			tempN=tempN[:-1]
			tempA.append(tempN)
			tempN=""
			if(line[x+1]=='='): 
				tempA.append("==")
				x+=1
			else: tempA.append("=")

		if(line[x]=='('):
			inFunc=1
			tempN=tempN[:-1]
			tempA.append(tempN)
			#words.append(tempN)
			tempN=""
		if(line[x]==')'):
			tempN=tempN[:-1]
			tempA.append(tempN)
			words.append(tempA)
			tempA=[]
			tempN=""
			inFunc=0
		if(line[x]==','):
			tempN=tempN[:-1]
			tempA.append(tempN)
			#words[count].append(tempN)
			inFunc+=1
			tempN=""

	Type=type(words[0])
	start=0
	if(Type!=""):
		con.data+="\t"+Type + "\t" + Type[0:2] + " 0\n"
		start=1

	exists = 0
	for x in range(start, len(words)):
		print(words[x])
		if(words[x]!="="): pass #checks for symbols then will run functions accordingly
		elif(words[x]!="=="): pass
		else:
			exists = checkExists(words[x])
			if(exists==0):
				print("function not found")
				quit()
			else: pass
	#if(Type==""):
	#	print("not a varible")
	#else: var()
