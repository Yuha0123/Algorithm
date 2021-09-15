import sys

input = sys.stdin.readline
#sys.stdin = open('./input.txt')

n, s = map(int, input().split())

nums = list(map(int, input().split()))

answer = 0
total = 0

def DFS(x):
    global total
    if x > n:
        return
    
    if x > 0 and total == s:
        global answer
        answer += 1
        
    for i in range(x, n):
        total += nums[i]
        DFS(i+1)
        total -=nums[i]
        
        
DFS(0)

print(answer)
