from funif import *
from reservedFunctions.exit import *
from reservedFunctions.print import FunPrint

def coreFun(words):
	if(words[0]=="if"): Funif(words)
	#elif(words[0]=="elif"):Funelif(words)
	#elif(words[0]=="else"):Funelse
	elif(words[0]=="print"):FunPrint(words)
	elif(words[0]=="exit"):Funexit()
	else: print("functions not implemented")