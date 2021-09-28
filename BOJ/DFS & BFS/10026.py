import sys
import collections
import copy 

input = sys.stdin.readline
sys.setrecursionlimit(100000)
#sys.stdin = open('./input.txt')


n = int(input())

# R % 2 == G % 2 == 0
R = 0
B = 1
G = 2

d = [[0,1], [1,0],[0,-1],[-1,0]]

board = list(list(-1 for _ in range(n)) for _ in range(n))

for i in range(n):
    s = input().strip()
    
    for j in range(n):
        if s[j] == 'R':
            board[i][j] = R
        elif s[j] == 'B':
            board[i][j] = B
        else:
            board[i][j] = G



def DFS(board, x, y, redgreen):
    if board[x][y] == -1:
        return
    
    cur_color = board[x][y] 
    
    board[x][y] = -1
    
    for i in range(4):
        new_x = x + d[i][0]
        new_y = y + d[i][1]
        
        if new_x < 0 or new_y < 0 or new_x >=n or new_y >= n:
            continue
        
        if redgreen == False and board[new_x][new_y] == cur_color:
            DFS(board, new_x, new_y, redgreen)
        elif redgreen == True and board[new_x][new_y] % 2 == cur_color % 2:
            DFS(board, new_x, new_y, redgreen)



#########################################################
result_normal = 0
result_redgreen = 0

board_redgreen = copy.deepcopy(board)

for i in range(n):
    for j in range(n):
        if board[i][j] != -1:
            DFS(board, i, j, False)
            result_normal += 1
        
        if board_redgreen[i][j] != -1:
            DFS(board_redgreen, i, j, True)
            result_redgreen += 1
            
print(result_normal, result_redgreen)
        


