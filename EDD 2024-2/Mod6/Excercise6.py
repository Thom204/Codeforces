import heapq as hq

cases = int(input())

for _ in range(cases):
    inn = list(map(int, input().split()))
    players = list(range(1, inn[0]+1))
    a = inn[1]
    b = inn[2]

    while len(players) > 1:
        for i in range(len(players)):
            p = (players[i]*a)%b
            players[i] = p

        hq.heapify(players)

        for ___ in range(len(players)//2):
            hq.heappop(players)
    
    print(players[0])
        