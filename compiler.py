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
for char in file:
    line+=char
    if(char == ';' or char=='{'):
        process(line)
        line=""

print(con.text)


assemble = open("ass.asm", "w")



