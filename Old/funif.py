#file contain rules for if else if(elif) and else
import config as con
from checkCondition import *


def Funif(words):
	name="if"+str(con.ifcount)
	con.ifcount+=1
	con.closeStack.append(name)
	checkcondition(words[2:], "")
	
def Funelif(words):
	pass

def Funelse(words):
	pass
