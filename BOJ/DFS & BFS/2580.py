import sys

input = sys.stdin.readline

#sys.stdin = open('./input.txt')

table = list(list(map(int, input().split())) for _ in range(9))
finished = False
zeros = []


def find_possible_num(x, y):
    possible_list = [1 for _ in range(10)]
    
    for i in range(9):
        possible_list[table[x][i]] = 0
        possible_list[table[i][y]] = 0
    
    row_start = (x//3) * 3
    col_start = (y//3) * 3
    
    for i in range(row_start,row_start + 3):
        for j in range(col_start, col_start + 3):
            possible_list[table[i][j]] = 0
            
    result = []
    
    for i in range(1,10):
        if possible_list[i]:
            result.append(i)
            
    return result
            
    
def DFS(i):
    global finished
    if finished == True:
        return
    if i == len(zeros):
        for row in range(9):
            for col in range(9):
                print(table[row][col], end=" ")
            print()
        
        finished = True
        return
    
    x, y = zeros[i]
    possible_list = find_possible_num(x,y)  

    for num in possible_list:
        table[x][y] = num
        DFS(i+1)
        table[x][y] = 0
    

for i in range(9):
    for j in range(9):
        if table[i][j] == 0:
            zeros.append((i,j))
            
DFS(0)
