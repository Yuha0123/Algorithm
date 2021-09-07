import sys
import collections

input = sys.stdin.readline
#sys.stdin = open('./input.txt')


n, m = map(int, input().split())

table = list(list(map(int,input().split())) for _ in range(n))

max_num = float('inf')
safety_dist = [[max_num for _ in range(m)] for _ in range(n)]

dr = [[0,1], [1,0], [0,-1], [-1,0], [1,1], [1,-1], [-1,1], [-1,-1]]

def BFS(i,j):
    q = collections.deque()
        
    q.append((i, j, 1))
    
    while q:
        x, y, dist = q.popleft()
        
        
        for k in range(8):
            new_x = x + dr[k][0]
            new_y = y + dr[k][1]
            
            if new_x >= 0 and new_y >=0 and new_x < n and new_y < m:
                if safety_dist[new_x][new_y] > dist:
                    safety_dist[new_x][new_y] = dist
                    q.append((new_x, new_y, dist + 1))
                

                    
            
            


for i in range(n):
    for j in range(m):
        if table[i][j] == 1:
            safety_dist[i][j] = 0
            BFS(i,j)

answer = 0

for i in range(n):
    for j in range(m):
        answer = max(answer, safety_dist[i][j])
        
print(answer)
