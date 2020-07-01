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

	for x in range(0, len(line)): #loops though 
		Type+=line[x]
		if(line[x]==' '):
			Type=Type[:-1]
			namPos=x+1
			break
	

	#sets a varible to store the output varible of the function
	Type= type(words[0][0]) #finds the defined type
	varType= Type + " " 	#from orginal way it was defined
	start =0				#used as compiler flag
	exists=[]				#
	reserved=[]
	if(varType=="fail "):
		exists = checkExistsFunction(words[0])
		reserved = checkReservedFunction(words[0])
		if(exists==[] and reversed==[]): #checks if function exists
			print("function not found")
			quit()
		elif(reversed!=[]):
			coreFun(words[0])
		else: pass

	elif(varType!="void"):	#only sets a varible if not void
		start=1
		varType+= varType[0:2]
		varType+=" 0"
		con.data+= "\t"+ varType+"\n"
	
	function = [] #stores what function and inputs
	for x in range(start, len(words)):
		if(len(words[x])>1): #behavour set if there is additional information with the funcition
			if(words[x][0]=="start"): con.inStart=1
			function.append(words[x][0])
			function.append(Type[0:2])
			for y in range(1, len(words[x])):
				function.append(words[x][y])
	
	exists=checkExistsFunction(function[0]) #checks against user defined vairbles to see if it defined
	reserved=checkReservedFunction(function) #checks against reseved functinos
	
	if(exists==[] and reserved ==[]): #if both empty defines the function	
		con.functions.append(function)#adds the varible name
		con.text+="_"+function[0]+":\n" #adds the label to the file defining new function
		con.closeStack.append(function[0]) #creates a list for puting a label at } to skip past segments when requred
	return
