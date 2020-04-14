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
		if(word==con.functions[x][0]):
			return con.functions[x]
	requried=[] #returns empty array if failed to find the functions
	return requried
