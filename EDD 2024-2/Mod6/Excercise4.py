import heapq as hq

cases = int(input())

for _ in range(cases):
    l = int(input())
    s = input()
    set = list(map(int, s.split()))
    hq.heapify(set)
    rest = 0
    for i in range(l//2, 0, -1):
        if l%2==0: 
            b = hq.heappop(set)*(10**(i-1))
        else: 
            b = hq.heappop(set)*(10**i)
            if len(set)==2:
                b+= hq.heappop(set)
        a = hq.heappop(set)*(10**(i-1))
        rest+= a+b

    print(rest)
