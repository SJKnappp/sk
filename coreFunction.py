from funif import *

def coreFun(words):
	if(words[0]=="if"): Funif(words)
	elif(words[0]=="elif"):Funelif(words)
	elif(words[0]=="else"):Funelse