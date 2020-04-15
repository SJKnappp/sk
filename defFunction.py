import config as con
from breakline import *
from checkExists import *
from coreFunction import *
from type import *

def function(line):
	length = len(line)
	Type=""
	name=""
	namPos=0

	words = breakline(line)
	print("fun")
	print(words)

	for x in range(0, len(line)): #loops though 
		Type+=line[x]
		if(line[x]==' '):
			Type=Type[:-1]
			namPos=x+1
			break
	
	#sets a varible to store the output varible of the function
	varType= type(words[0]) +" "
	if(varType=="fail "):
		exists = checkExistsFunction(words[0])
		if(exists==[]): #checks if function exists
			print("function not found")
			quit()
		else:
			coreFun(words[0])
	elif(varType!="void"):	#only sets a varible if not void
		varType+= varType[0:2]
		varType+=" 0"
		con.data+= "\t"+ varType+"\n"
	

	if(varType=="fail "):
		namPos=0

	#function name
	varName=""
	nameend=x
	for x in range(namPos, len(line)):
		varName+=line[x]
		if(line[x]=='('):
			varName=varName[:-1]
			nameEnd=x
			break
		if(line[x]=='{'): #thouws error if () not found
			print("function declration requires ()")
			quit()

	if(varName=="start"): con.inStart=1

	con.functions.append(varName)#adds the varible name

	con.text+="_"+varName+":\n" #adds the label to the 

	return
