import sys
import collections

sys.setrecursionlimit(10**9)
input = sys.stdin.readline
#sys.stdin = open('./input.txt')

d = [[0,1], [1,0], [0, -1], [-1, 0]]

#인접한 배추는 방문 후 0으로 만들기 
def DFS(board, i, j):
    if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
        return
    if board[i][j] == 0:
        return
    
    board[i][j] = 0
    
    for k in range(len(d)):
        DFS(board, i + d[k][0], j + d[k][1])
    


t = int(input())

for _ in range(t):
    m, n, k = map(int, input().split())
    
    board = list(list(0 for _ in range(m)) for _ in range(n))
    
    v = []
    
    for _ in range(k):
        x, y = map(int, input().split())
        
        board[y][x] = 1
        
        v.append((y,x))
        
    cnt = 0
    
    for i, j in v:
        if board[i][j] == 1:
            DFS(board,i,j)
            cnt += 1
            
    print(cnt)
