import math

def solution(n, s, a, b, fares):
    edges = [ list(200000 for _ in range(n + 1)) for _ in range(n + 1)]
    
    for i in range(n + 1):
        edges[i][i] = 0
    
    for fare in fares:
        edges[fare[0]][fare[1]] = fare[2]
        edges[fare[1]][fare[0]] = fare[2]
        
    
    for k in range(1,n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if edges[i][k] + edges[k][j] < edges[i][j]:
                    edges[i][j] = edges[i][k] + edges[k][j]
    
    
    
    answer = math.inf
    
    for i in range(1, n + 1):
        if answer > edges[s][i] + edges[i][a] + edges[i][b]:
            answer = edges[s][i] + edges[i][a] + edges[i][b]
    
    
    return answer
