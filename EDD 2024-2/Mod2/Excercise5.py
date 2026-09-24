def repartir (n, m, args):
    billetes= args
    distribucion= tuple((0,)*n)
    
    for i in range(0,m,1):
        actor= i%n
        actual= distribucion[actor]
        billete= billetes[i]
        distribucion= distribucion[:actor] + (actual+billete, ) + distribucion[actor+1:]
    
    return max(distribucion)-min(distribucion)


n=int(input())
outTuple=()

for i in range(n):
    values= tuple(map(int, input().split(' ')))
    billetes= tuple(map(int, input().split(' '))) 
    outTuple= outTuple + (repartir(values[0], values[1], billetes),)

for i in outTuple:
    print(i)