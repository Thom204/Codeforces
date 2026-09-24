ini=0
second=1
aux=0

N= int(input())

print(1)
for i in range(N-1):
    aux= ini+second
    print(aux)
    ini= second
    second=aux