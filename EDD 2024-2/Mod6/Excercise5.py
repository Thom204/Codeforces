import heapq as hq


duration = int(input())
numLines = int(input())
beats = {}
beat = []


for _ in range(numLines):
    inn = input().split()
    beats[inn[0]] = [int(inn[1]), int(inn[2])]
    beat.append(int(inn[1]))

hq.heapify(beat)
ms = 0
nex = 0

while ms<=duration:
    #print(beat)
    for i in beats:
        #print(beats[i])
        if beats[i][0]== ms:
            print(ms)
            nex = beats[i][0]+ beats[i][1]
            beats[i][0] = nex
            #print(nex)
            hq.heappush(beat, nex)    
    
    ms = hq.heappop(beat)
