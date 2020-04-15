#checks condition 
import config as con

def checkcondition(word, label):
	check=0
	condition=""
	for x in range(0, len(word)):
		if(word[x]=="=="): 
			condition="je"
			check = 1 
		elif(word[x]==">"): 
			condition="jg"
			check = 1 
		elif(word[x]=="<"): 
			condition="jl"
			check = 1 
		