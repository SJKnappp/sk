
#breaks line in indvidual compenets in an array
def breakline(line):
	words=[]
	tempN="" #varible name
	tempA=[] #varible data
	tempFunc=[] #stores info on function to process
	inFunc=0 #keeps track of in function
	count=0 #keeps track of the number entrys
	countIn=0 #keeps track of number a varibles in funcion call
	for x in range(0, len(line)): #loops thrugh the string to split them into lines
		tempN+=line[x]
		if(line[x]==' ' and inFunc==0 or line[x]==';' or line[x]=='{'): #stores temp value at the end of the entry
			count+=1	#incrments the count
			tempN=tempN[:-1]	#removes the end stament
			tempA.append(tempN)
			if(tempN!=''):		#removes any entre that is empty caused by double spaces
				words.append(tempA) #adds the indvdual parts of the line 
			tempN=""
			tempA=[]
		
		elif(line[x]=='='): #checks for keysymble =
			tempN=tempN[:-1]	
			if(tempN!=""): words.append(tempN) #checks if entry is not empty
			tempN=""	
			if(line[x+1]=='='): 
				words.append("==")	#checks if equality or if check exists
				x+=1				#incremts x pos to not include = twice
			else: words.append("=")	#if not == and = already been checked for places it

		elif(line[x]=='('): #chages into a varible call
			inFunc=1
			tempN=tempN[:-1]
			tempA.append(tempN.strip())
			#words.append(tempN)
			tempN=""
		elif(line[x]==')'):
			tempN=tempN[:-1]
			tempA.append(tempN.strip())
			#tempA.append(tempFunc)
			words.append(tempA) #adds 
			tempA=[]
			tempN=""
			inFunc=0
		elif(line[x]==','):
			tempN=tempN[:-1]
			tempA.append(tempN.strip())
			#words[count].append(tempN)
			inFunc+=1
			tempN=""
	return words
