n=int(input())
jSo=tuple(map(int, input().split(", ")))
jLa=tuple(map(int, input().split(", ")))
jRis=tuple(map(int, input().split(", ")))
so=0 
la=0 
ris=0

for i in range(0,n,1):
    sum=(jSo[i]+jLa[i]+jRis[i])%2

    if(jSo[i]%2==sum):so+=1
    if(jLa[i]%2==sum):la+=1
    if(jRis[i]%2==sum):ris+=1

print(f'SO:{so} LAR:{la} IS:{ris}')