import heapq

A=[]
B=[]
C=[]
pa=0
pb=0
pc=0
compare=[]

while True:
    turn= list(map(str, input().split()))

    if turn[0]=="fin":
        print("Equipo A:", pa)
        print("Equipo B:", pb)
        print("Equipo C:", pc)
        break


    elif turn[0]=="menores":

        if len(A)!=0:
            a= heapq.heappop(A)
        else: a=1001

        if len(B)!=0:
            b= heapq.heappop(B)
        else: b=1001

        if len(C)!=0:
            c =heapq.heappop(C)
        else: c=1001

        if a+b+c==3003:
            continue

        pa+=int(a<=b and a<=c)
        pb+=int(b<=a and b<=c)
        pc+=int(c<=a and c<=b)

        
        

    else:
        if turn[0] == "A":
            heapq.heappush(A, int(turn[1]))
        elif turn[0]== "B":
            heapq.heappush(B, int(turn[1]))
        else:
            heapq.heappush(C, int(turn[1]))