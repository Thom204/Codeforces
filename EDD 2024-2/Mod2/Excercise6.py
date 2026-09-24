def recorrer(m, map):
    pos= 0
    acm= 0
    steps=tuple()
    while(pos >= 0 and pos<m):
        step= map[pos]
        steps= steps+ (pos,)
        pos= pos+step
        acm+=1

        if(pos in steps): 
            break
    return acm

n=int(input())
out=  tuple()

for i in range(0,n,1):
    m= int(input())
    t=tuple(map(int, input().split(' ')))
    out= out+ (recorrer(m, t),)
for i in out:
    print(i)