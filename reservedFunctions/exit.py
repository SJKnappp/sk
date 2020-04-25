import config as con 

def Funexit(): #exits the program from that point
	con.text+="\tmov\teax, 1\n\tint\t0x80\n"
	return