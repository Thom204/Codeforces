def depurarFila(dct):
    for i in reversed(list(dct)):
        if dct[i]<len(dct):
            dct.pop(i)
            break
    print(dct)


dct={}
while(True):
    fans=input().split(' ')
    if fans != ['0', '0']:
        tol=int(fans[1])
        if len(dct) <= tol:            
            dct[fans[0]]= tol 
            depurarFila(dct)
    else: 
        break

print(len(dct))