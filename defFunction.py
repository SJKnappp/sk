import config as con
from type import *

def function(line):
	length = len(line)
	Type=""
	name=""

	for x in range(0, 5):
		Type+=line[x]
		if(line[x]==' '):
			Type=Type[:-1]
			break
	
	
	varName= type(Type) 
	varName+=" db 0"
	
	con.data+=varName
	print(con.data)

	for x in range (4, length):
		name+=line[x]
		if(line[x]=='('):
			name=name[:-1]
			break

	return
