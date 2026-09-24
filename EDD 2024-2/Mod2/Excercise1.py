N= int(input())
s= str(input())
arr= s.split(" ")
acm= int(arr[-1])

for i in range(N-1, 0, -1):
    acm += int(arr[i-1])
    print(acm)