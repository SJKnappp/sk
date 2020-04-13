import config as con

#checks it uses defined varibles
def checkExists(word):
	#defined list 
	for x in range(0, len(con.functions)): #split into two diffrent lists as they behave very diffrently
		if(word==con.functions[x][0]):
			return 1

	return 0
	#user defined varibles
