from collections import deque

Casos = int(input())
for _ in range(Casos):
    pcs = deque(map(int, input().split()))
    h = len(pcs)

    for i in range(h):
        a = pcs.pop()
        b = pcs.pop()

        if (a + b)%2 == 0:
            pcs.append((a + b) // 2)
            h -= 1
        else:
            pcs.append(b)
            pcs.append(a)
        if h <= 1:
            break
        
    print(f'{len(pcs)} {pcs[len(pcs)-1]}')