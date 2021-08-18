import sys

input = sys.stdin.readline

#sys.stdin = open('./input.txt')

n, m = map(int, input().split())


trees = list(map(int, input().split()))

low = 0
high = max(trees)

while low <= high:
    mid = (low + high)//2
    
    total = 0
    for tree in trees:
        if tree > mid:
            total += tree - mid
        if total > m:
            break
        
    if total == m:
        high = mid
        break
    elif total > m:
        low = mid + 1
    else:
        high = mid - 1
        
print(high)
