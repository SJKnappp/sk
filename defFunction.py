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
			namPos=0
			break
	
	#sets a varible to store the output varible of the function
	varName= type(Type) +" "
	if(varName!="void"):	#only sets a varible if not void
		varName+= varName[0:2]
		varName+=" 0"
		con.data+=varName

	for x in range (4, length):
		name+=line[x]
		if(line[x]=='('):
			name=name[:-1]
			break

	return
