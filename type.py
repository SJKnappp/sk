from config import *

#get the first availible varible(reasment not implemted)
def type(string):
	name=""
	if(string=="char"):
		name="db"+len(db)
		db.append(f'{name}')
	elif(string=="i8"):
		name="db"+len(db)
		db.append(f'{name}')
	elif(string=="u8"):
		name="db"+len(db)
		db.append(f'{name}')
	elif(string=="i16"):
		name="do"+len(do)
		db.append(f'{name}')
	elif(string=="u16"):
		name="do"+len(do)
		db.append(f'{name}')
	elif(string=="i32"):
		name="dy"+len(dy)
		db.append(f'{name}')
	elif(string=="u32"):
		name="dy"+len(dy)
		db.append(f'{name}')
	elif(string=="i64"):
		name="dz"+len(dz)
		db.append(f'{name}')
	elif(string=="u64"):
		name="dz"+len(dz)
		db.append(f'{name}')

	return name