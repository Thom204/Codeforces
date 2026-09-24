def bubbleSort(array):
    ctr=0
    for i in range(len(array)):
        for j in range(0, len(array) - i - 1):
            if array[j] > array[j + 1]:
                ctr+=1
                array[j], array[j + 1] = array[j + 1], array[j]
    return ctr

cases= int(input())
L=[]

for i in range(cases):
    L= list(map(int, input().split()))
    print(bubbleSort(L))