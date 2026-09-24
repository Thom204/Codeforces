def depurarFila(fila, maximos):
    print(maximos[fila[-1]])
    while len(fila) > maximos[-1]:
        fanatico_a_salir = fila[0] 
        for fanatico in fila:
            if maximos[fanatico] < maximos[fanatico_a_salir]:
                fanatico_a_salir = fanatico
        fila.remove(fanatico_a_salir)


fila = []
maximos = {}

while True:
    fans = input().split(' ')
    if fans[0] == '0' and fans[1] == '0':
        break
    
    tol= int(fans[1])
    maximos[fans[0]] = tol
    
    if len(fila) < tol:
        fila.append(id)
    else:
        depurarFila(fila, maximos)
        if len(fila) < tol:
            fila.append(id)

print(len(fila))