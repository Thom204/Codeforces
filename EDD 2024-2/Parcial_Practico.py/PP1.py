import heapq
club = []
while True:
    N = input().split()
    if N[0] == "fin":
        break

    if N[0] == "ingresa":
        P = -int(N[1])

        if not club:
            heapq.heappush(club, P)
            print("adelante")
 
        elif (club[0]/2) >= (P):
            heapq.heappush(club, P)
            print("adelante")

        else:
            print("denegado")

 
    elif N[0] =="salida":
        if club:
            heapq.heappop(club)
            print("hasta pronto")