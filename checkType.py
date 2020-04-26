#check that data compatible to the type
def checkType(Type, data):
	if(Type=='u8'): 
		if(data>-1 and data <256):
			return 1
	if(Type=='i8'):
		if(data>-129 and data<128):
			return 1
	return 0