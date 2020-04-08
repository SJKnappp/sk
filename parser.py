def parse(data):
    
    lcount=0    

    for line in data:
        count=0
        curly=0
        startfound=0

        line=line.rstrip()
        if(line!=""):
            if(line=="int start(){"):
                startfound =1
        
            open=0
            lenght = len(line)
            if(line[-1]=='\n'):
                lenght-=1

            for char in line:
                count+=1
            
                if(char=='('): open+=1
                elif(char==')'): open-=1
                elif(char=='{'): curly+=1
                elif(char=='}'): curly-=1

                if(char==';'):
            
                    if(open>0):
                        print(f'too many open brackets on line{lcount} with open {open} and closed {closed}')
                        quit()
                    elif(open<0):
                        print(f'too many closed brackets on line{lcount} with open {open} and closed {closed}')
                        quit()
                elif(lenght==count and char !=';'): 
                    print(f'missing ; on line {lcount}')
        
        lcount+=1

    if(startfound==0):
        print("main function not found")
        quit



