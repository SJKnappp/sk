from defFunction import *
from defvar import *
from checkExists import *
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

	words=[]
	tempN="" #varible name
	tempA=[] #varible data
	tempFunc=[] #stores info on function to process
	inFunc=0 #keeps track of in function
	count=0 #keeps track of the number entrys
	countIn=0 #keeps track of number a varibles in funcion call
	for x in range(0, len(line)): #loops thrugh the string to split them into lines
		tempN+=line[x]
		if(line[x]==' ' or line[x]==';' or line[x]=='{'): #stores temp value at the end of the entry
			count+=1	#incrments the count
			tempN=tempN[:-1]	#removes the end stament
			tempA.append(tempN)
			if(tempN!=''):		#removes any entre that is empty caused by double spaces
				words.append(tempA) #adds the indvdual parts of the line 
			tempN=""
			tempA=[]
		
		elif(line[x]=='='): #checks for keysymble =
			tempN=tempN[:-1]	
			if(tempN!=""): words.append(tempN) #checks if entry is not empty
			tempN=""	
			if(line[x+1]=='='): 
				words.append("==")	#checks if equality or if check exists
				x+=1				#incremts x pos to not include = twice
			else: words.append("=")	#if not == and = already been checked for places it

		elif(line[x]=='('): #chages into a varible call
			inFunc=1
			tempN=tempN[:-1]
			tempA.append(tempN)
			#words.append(tempN)
			tempN=""
		elif(line[x]==')'):
			tempN=tempN[:-1]
			tempA.append(tempN)
			#tempA.append(tempFunc)
			words.append(tempA) #adds 
			tempA=[]
			tempN=""
			inFunc=0
		elif(line[x]==','):
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

	print(words)

	exists = 0

	for x in range(start, len(words)):
		print(words[x])

		if(len(words[x])==1): pass
		elif(len(words[x]>1)):
			checkExistsFunction(words[x][0])
			for y in range(1, len(words[x])):
				words[x]





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
