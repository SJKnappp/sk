import config as con 

def Funexit():
	con.text+="\tmov\teax, 1\n\tint\t0x80\n"
	return