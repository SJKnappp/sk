import config as con

#get the first availible varible(reasment not implemted)
def type(string):
	name=""
	if(string=="char"):
		name="db"+str(len(con.db))
		con.db.append(f'{name}')
	elif(string=="i8"):
		name="db"+str(len(con.db))
		con.db.append(f'{name}')
	elif(string=="u8"):
		name="db"+str(len(con.db))
		con.db.append(f'{name}')
	elif(string=="i16"):
		name="do"+str(len(con.do))
		con.db.append(f'{name}')
	elif(string=="u16"):
		name="do"+str(len(con.do))
		con.db.append(f'{name}')
	elif(string=="i32"):
		name="dy"+str(len(con.dy))
		con.db.append(f'{name}')
	elif(string=="u32"):
		name="dy"+str(len(con.dy))
		con.db.append(f'{name}')
	elif(string=="i64"):
		name="dz"+str(len(con.dz))
		con.db.append(f'{name}')
	elif(string=="u64"):
		name="dz"+str(len(con.dz))
		con.db.append(f'{name}')
	elif (string=="void"):
		name="void"
	else: name="fail"

	return name