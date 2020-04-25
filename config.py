#defines all global varible to be used 
global db, dw, dd, dq, dt, do, dy, dz, data, bss, text
db=[]   #1byte
dw=[]   #2byte
dd=[]   #4byte
dq=[]   #8byte
dt=[]   #10byte
do=[]   #16byte
dy=[]   #32byte
dz=[]   #64byte

functions = [] #stores all avilable functions
varibles = []  #stores all vairbles 
reservedFunctions = [["if"], ["elif"], ["else"]] #all of the predefined functions

ifcount=0
blockcount=0

closeStack=[] #stores lables to close definitions

inStart=0 #tracks if in start fucntion as exit behavour is diffrent

#tracks the three segments
data=""
bss=""
text=""
