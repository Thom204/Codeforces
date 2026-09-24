import heapq

cases = int(input())

for i in range(cases):
    conj = list(map(int, input().split()[:-1]))
    ctr = len(conj)
    heapq.heapify(conj)


    while(ctr > 2):
        a = heapq.heappop(conj)
        b = heapq.heappop(conj)
        heapq.heappush(conj, a+b)
        ctr-=1
    print(*conj)