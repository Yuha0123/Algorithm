import sys
import collections

input = sys.stdin.readline

#sys.stdin = open('./input.txt')

n, m = map(int, input().split())

pivot = 1 << 17

max_val = 1000000001

min_tree = [max_val for _ in range(pivot*2)]
max_tree = [0 for _ in range(pivot*2)]

def init_tree():
    for i in range(pivot - 1,0, -1):
        min_tree[i] = min(min_tree[2*i], min_tree[2*i + 1])
        max_tree[i] = max(max_tree[2*i], max_tree[2*i + 1])

def query_tree(a, b):
    l = a + pivot
    r = b + pivot
    
    min_result = float('inf')
    while l <= r:
        if l % 2 == 1:
            min_result = min(min_result, min_tree[l])
            l += 1
        if r % 2 == 0:
            min_result = min(min_result, min_tree[r])
            r -= 1
        
        l = l // 2
        r = r // 2
    
    l = a + pivot
    r = b + pivot
    
    max_result = float('-inf')
    while l <= r: 
        if l % 2 == 1:
            max_result = max(max_result, max_tree[l])
            l += 1
        if r % 2 == 0:
            max_result = max(max_result, max_tree[r])
            r -= 1
            
        l = l // 2
        r = r // 2
    
    print(min_result,max_result)
    

################## main #################
for i in range(n):
    num = int(input())
    
    min_tree[i + pivot] = num
    max_tree[i + pivot] = num

init_tree()

for _ in range(m):
    a, b = map(int, input().split())
    query_tree(a - 1,b - 1)
    
