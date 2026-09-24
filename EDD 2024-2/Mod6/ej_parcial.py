def bs_improved(A):
    L = A
    while True:
        i = len(L)//2
        e = L[i]

        if e > L[0]:
            if len(L)==2:
                return L[-1] 
 
            if L[i+1] < e:
                return e
            else:
               L= L[i:]
        
        else:
            if L[i-1] > e:
                return L[i-1]
            else:
                L= L[:i]

def UN_detect(str):
    obj1= "UNAL"
    obj2= "LANU"

    for i in str:
        if obj1!="" and obj2!="":
            if obj1[0] == i:
                obj1= obj1[1:]
            
            if obj2[0] == i:
                obj2= obj2[1:]
        
    if obj1 == "" or obj2=="":
        return "SI"
    else:
        return "NO"
    
    
print(bs_improved([1,2,4,8,10]))

#n = int(input())

#for _ in range(n):
#    print(UN_detect(input().split()))
