from collections import deque

uroboro = deque()
while True:
    entrada = tuple(map(str, input().split()))

    if entrada[0] == "termina":
        break
    
    if entrada[0] == "agrega":
        uroboro.append(int(entrada[1]))

    if entrada[0] == "engulle":
        cola = uroboro[-1]
        if uroboro[0] > cola:
            uroboro.pop()
        else:
            uroboro.popleft()

if len(uroboro) == 0:
    print("uroboro vacio")
else:
    print("cabeza", uroboro[0] , "cola", uroboro[-1])