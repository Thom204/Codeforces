L=[]

while(True):
    i=int(input())
    if(i==0):
        break
    else:
        if(i in L):
            L.remove(i)
        elif(i+1 in L):
            L.remove(i+1)
        elif(i-1 in L):
            L.remove(i-1)
        else:
            L.append(i)

if (L==[]):
    L.append(0)
for e in L:
    print(e, end=' ')