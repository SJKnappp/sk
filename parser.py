def parse(data):
    
    lcount=0    

    for line in data:
        count =0
        
        
        open=0
        closed=0
        lenght = len(line)
        if(line[-1]=='\n'):
            lenght-=1

        for char in line:
            count+=1
            
            if(char=='('): open+=1
            elif(char==')'): closed+=1

            if(char==';'):
            
                if(open>closed):
                    print(f'too many open brackets on line{lcount} with open {open} and closed {closed}')
                    quit()
                elif(open<closed):
                    print(f'too many closed brackets on line{lcount} with open {open} and closed {closed}')
                    quit()
            elif(lenght==count and char !=';'): 
                print(f'missing ; on line {lcount}')
        
        lcount+=1


