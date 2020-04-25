from funif import *
from reservedFunctions.exit import *

def coreFun(words):
	print("fek")
	print(words)
	if(words[0]=="if"): Funif(words)
	elif(words[0]=="elif"):Funelif(words)
	elif(words[0]=="else"):Funelse
	elif(words[0]=="exit"):Funexit()
	else: print("functions not found")