import config as con
from type import *

def function(line):
	length = len(line)
	Type=""
	name=""
	namPos=0

	for x in range(0, len(line)):
		Type+=line[x]
		if(line[x]==' '):
			Type=Type[:-1]
			namPos=x+1
			break
	
	#sets a varible to store the output varible of the function
	varType= type(Type) +" "
	if(varType!="void"):	#only sets a varible if not void
		varType+= varType[0:2]
		varType+=" 0"
		con.data+= "\t"+ varType+"\n"

	#function name
	varName=""
	nameend=x
	for x in range(namPos, len(line)):
		varName+=line[x]
		if(line[x]=='('):
			varName=varName[:-1]
			nameEnd=x
			break
		if(line[x]=='{'):
			print("function declration requires ()")
			quit()

	if(varName=="start"): con.inStart=1

	con.functions.append(varName)#adds the varible name

	con.text+="_"+varName+":\n" #adds the label to the 



	for x in range (4, length):
		name+=line[x]
		if(line[x]=='('):
			name=name[:-1]
			break

	return
