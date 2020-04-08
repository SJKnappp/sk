from parser import *

source = open("print.k", "r")
data = source.readlines()

print(data)

#remove file formating a turn into a single string
file=""
for line in data:
    line.strip()
    for char in line:
        if(char=='\t'): pass
        else: file+=char

print(file)

print("starting compile")

#parser
parse(file)

t=""
for line in source:
    line.strip()
    for char in line:
        t+=char

print(t)




assemble = open("ass.asm", "w")



