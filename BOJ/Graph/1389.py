import sys
import collections

input = sys.stdin.readline
#sys.stdin = open('./input.txt')

MAX = 1000

n, m = map(int, input().split())

friends = list(list(MAX for _ in range(n)) for _ in range(n))

for i in range(n):
    friends[i][i] = 0

for _ in range(m):
    x, y =  map(int, input().split())
    
    friends[x - 1][y - 1] = 1
    friends[y - 1][x - 1] = 1
    

for k in range(n):
    for i in range(n):
        for j in range(n):
            new = friends[i][k] + friends[k][j]
            if friends[i][j] > new:
                friends[i][j] = new
                
                

kevin_bacon = list(0 for _ in range(n))

for i in range(n):
    kevin_bacon[i] = sum(friends[i])
    
print(kevin_bacon.index(min(kevin_bacon)) + 1)
