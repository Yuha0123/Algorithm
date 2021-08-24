import sys
import collections

input = sys.stdin.readline

#sys.stdin = open('./input.txt')


n, m = map(int, input().split())

q = []

visited = [0 for _ in range(n + 1)]

def DFS(x):
    if x > m:
        return
    if x == m:
        for i in range(m):
            print(q[i], end=" ")
        print()
        
        return
    
    for i in range(1, n+1):
        if visited[i] == 0:
            q.append(i)
            visited[i] = 1
        else:
            continue
        DFS(x + 1)
        q.pop()
        visited[i] = 0

DFS(0)