from bisect import bisect_left

len =int(input())
postes= list(map(int, input().split(' ')))
postes.sort()
cases= int(input())
out= []

for i in range(cases):
    h= input().split(' ')
    ini= bisect_left(postes, int(h[0]))
    end = bisect_left(postes, int(h[1]))
    print(f'{abs(ini- end)} kms')
