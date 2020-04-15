import config as con

#checks it uses defined varibles
def checkExists(word, funNum):
	#defined list 
	for x in range(0, len(con.varibles)): #split into two diffrent lists as they behave very diffrently
		if(word==con.varibles[x][funNum][0]):
			return 1

	return 0
	#user defined varibles

def checkExistsFunction(word): #finds if function exists then returns the requirements
	#defined function list
	for x in range(0, len(con.functions)): #loops though all of known varibles
		if(word==con.functions[x][0]): #program defined functions
			return con.functions[x]
	requried=[] #returns empty array if failed to find the functions(will be used so that try and catch type arrangments can be used )
	return requried

def checkReservedFunction(word):
	for x in range(0, len(con.reservedFunctions)):
		if(word[0]==con.reservedFunctions[x][0]):
			return con.reservedFunctions[x]
	requried=[] #returns empty array if failed to find the functions(will be used so that try and catch type arrangments can be used )
	return requried
