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
	Type= type(words[0][0]) +" "
	varType= Type + " "
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
	
	function = []
	for x in range(1, len(words)):
		if(len(words[x])>1):
			if(words[x][0]=="start"): con.inStart=1
			function.append(words[x][0])
			function.append(Type[0:2])
			for y in range(1, len(words[x])):
				function.append(words[x][y])

	con.functions.append(function)#adds the varible name
	con.text+="_"+function[0]+":\n" #adds the label to the 

	return
