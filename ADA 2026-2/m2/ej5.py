n = int(input())
for i in range(n):
    c = list(map(int, input().split(" ")))
    a = c[0]
    b = c[1]

    count = 0
    ni = 1

    while ni <= b:
        if ni >= a:
            count += 1

        divisores_i = 0
        raiz = int(ni**0.5)
        for j in range(1, raiz + 1):
            if ni % j == 0:
                if j * j == ni:
                    divisores_i += 1
                else:
                    divisores_i += 2

        ni += divisores_i
        print(ni)

    print(count)