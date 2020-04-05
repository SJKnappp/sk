from parser import *

#parser
source = open("print.k", "r")
data = source.readlines()

print("starting compile")

parse(data)