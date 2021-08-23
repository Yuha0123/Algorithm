import sys
import heapq


def get_index(n, x, y):
    return n*x + y


input = sys.stdin.readline

#sys.stdin = open('./input.txt')


d = [[1,0],[0,1],[-1,0],[0,-1]]

cnt = 1

while True:
    n = int(input())
    
    if n == 0:
        break
    
    nodes = list(list(map(int,input().split())) for _ in range(n))
    
    q = []
    distance = [float('inf') for _ in range(n*n)]
    
    heapq.heappush(q, (nodes[0][0], (0,0)))

    while q:
        cost = q[0][0]
        coord = q[0][1]
        
        heapq.heappop(q)
        
        if distance[get_index(n, coord[0], coord[1])] != float('inf'):
            continue
        else:
            distance[get_index(n, coord[0], coord[1])] = cost
            if coord[0] == n - 1 and coord[1] == n - 1:
                break
        
        for i in range(4):
            next_x = coord[0] + d[i][0]
            next_y = coord[1] + d[i][1]
            
            if next_x == n or next_x < 0 or next_y == n or next_y < 0:
                continue
            
            new_cost = cost + nodes[next_x][next_y]
            heapq.heappush(q, (new_cost, (next_x,next_y)))
            
    print("Problem ", cnt, ": ", distance[get_index(n, n-1,n-1)], sep="")
    cnt += 1
