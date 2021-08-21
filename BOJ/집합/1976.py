import sys
import collections

input = sys.stdin.readline

#sys.stdin = open('./input.txt')

n = int(input())
m = int(input())

parent = list(-1 for _ in range(n + 1))


def find_parent(a):
    if parent[a] == -1:
        return a
    
    p = parent[a]
    parent[a] = find_parent(p)
    
    return parent[a]
    

def union_set(a, b):
    pa = find_parent(a)
    pb = find_parent(b)
    
    if pa != pb:
        parent[pa] = pb


################ main ###################

for i in range(1, n+1):
    datas = list(map(int, input().split()))
    
    for j in range(n):
        if datas[j] == 1:
            union_set(i,j + 1)
            
schedule = list(map(int, input().split()))
    
flag = True
p = find_parent(schedule[0])

for city in schedule:
    if find_parent(city) != p:
        flag = False
        break

if flag:
    print("YES")
else:
    print("NO")
