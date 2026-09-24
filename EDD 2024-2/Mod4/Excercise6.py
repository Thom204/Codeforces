def combine(weights):
    weights.sort()
    left_sum = 0
    right_sum = sum(weights)
    min_diff= abs(weights[0]- right_sum)
    
    for i in range(len(weights) - 1):
        left_sum += weights[i]
        right_sum -= weights[i]
        
        min_diff = min(min_diff, abs(left_sum - right_sum))
    
    return min_diff

C = int(input())
    
for _ in range(C):
    weights = list(map(int, input().split(", ")))
    result = combine(weights)
    print(result)