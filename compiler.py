from parser import *
from assem import *
import config as con

source = open("print.k", "r")
output = open("run.asm", "w")
data = source.readlines()

#list of varibles avilble to reasign


#remove file formating a turn into a single string
file=""
for line in data:
	line.strip()
	for char in line:
		if(char=='\t' or char=='\n'): pass
		else: file+=char

print(file)

print("starting compile")

#parser
parse(data)

t=""
for line in source:
	line.strip()
	for char in line:
		t+=char

print(t)

#process line by line
line=""
ignore=0
for char in file:
	
	if(ignore==0): line+=char
	if((char == ';' or char=='{' or char=='}') and ignore==0):
		process(line)
		line=""
	if(char == '#' and ignore==0): 
		print("test")
		ignore=1
		line=line[:-1]
		continue

	if(char == '#' and ignore==1): ignore=0

assemble = open("ass.asm", "w")
assemble.write(f'section .data\n{con.data}')
assemble.write(f'section .bss\n{con.bss}')
assemble.write(f'section .text\n\tglobal _start\n{con.text}')



