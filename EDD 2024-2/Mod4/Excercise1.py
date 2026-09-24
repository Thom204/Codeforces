from bisect import bisect_left

sL= int(input())
L= tuple(map(int, input().split()))
sN= int(input())
N= tuple(map(int, input().split()))
s=0
p=0

for i in N:
    p= bisect_left(L, i)
    if p < sL and L[p]==i:
        s+= p+1

print(s)