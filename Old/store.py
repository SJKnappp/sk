import config as con

#add to data point turned into functions to standardise
def dataAdd(foo, newline, tab):
	if(newline==1):con.data+="\n"
	if(tab==1):con.data+="\t"
	con.data+=foo
	return

def bssAdd(foo, newline, tab):
	if(newline==1):con.bss+="\n"
	if(tab==1):con.bss+="\t"
	con.bss+=foo
	return

def textAdd(foo, newline, tab):
	if(newline==1):con.text+="\n"
	if(tab==1):con.text+="\t"
	con.text+=foo
	return