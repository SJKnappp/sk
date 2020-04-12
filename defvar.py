import config as con
from type import *

def var(line):
	length = len(line)
	Type=""
	name=""

	
	
	varName= type(Type) +" "
	varName+= varName[0:2]
	varName+=" 0"
	
	con.data+=varName

	for x in range (4, length):
		name+=line[x]
		if(line[x]=='('):
			name=name[:-1]
			break

	return
