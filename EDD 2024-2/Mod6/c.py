import heapq

n = int(input())

for _ in range(n):
    maxh=[]
    minh=[]
    a= list(map(int,input().split()))
    for i in a:
        heapq.heappush(maxh, -i)
        heapq.heappush(minh, i)
    heapq.heappop(maxh)
    heapq.heappop(minh)

    print(maxh[0]*-1 - minh[0])