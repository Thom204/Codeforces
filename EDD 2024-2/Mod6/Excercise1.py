import heapq

ulti=0
arr=[]
while True:
    turn= input()

    if turn== "end":
        print(ulti)
        break

    elif turn== "sig":
        if(len(arr)==0):
            continue
        ulti= heapq.heappop(arr)

    else:
        heapq.heappush(arr, int(turn))
