import sys
import collections

input = sys.stdin.readline

#sys.stdin = open('./input.txt')

n, m = map(int, input().split())

arr = []

def DFS(x):
    if x > n + 1:
        return
    if len(arr) == m:
        for i in range(m):
            print(arr[i], end=" ")
        print()
        return
    
    for i in range(x, n+1):
        arr.append(i)
        DFS(i+1)
        arr.pop()
        
DFS(1)
        
