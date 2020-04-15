#file contain rules for if else if(elif) and else
import config as con


def Funif(words):
	name="if"+str(con.ifcount)
	con.ifcount+=1
	con.closeStack.append(name)
	

def Funelif(words):
	pass

def Funelse(words):
	pass
