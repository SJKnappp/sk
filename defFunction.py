from config import *


def function(line):
	length = len(line)
	type=""
	name=""

	for x in range(0, 5):
		type+=line[x]
		if(line[x]==' '):type=type[:-1]
	varName= ""#type(type) 
	varName+="db 0\n"
	
	data+=varName

	for x in range (4, length):
		name+=line[x]
		if(line[x]=='('):
			name=name[:-1]
			break

	output.write(f'_{name}')
