import sys
import collections

input = sys.stdin.readline
#sys.stdin = open('./input.txt')

n, m = map(int, input().split())

parent = list(-1 for _ in range(n + 1))

def find_parent(i):
    if parent[i] == -1:
        return i
    
    p = parent[i]
    parent[i] = find_parent(p)
    
    return parent[i]

def union_set(a, b):
    pa = find_parent(a)
    pb = find_parent(b)
    
    if pa != pb:
        if truth[pa]:
            parent[pb] = pa
        else:
            parent[pa] = pb

####################################

truth = [0 for _ in range(n + 1)]

datas = list(map(int, input().split()))

for i in range(1, datas[0] + 1):
    truth[datas[i]] = 1


party = []
for i in range(m):
    datas = list(map(int, input().split()))
    party.append(datas[1:])
    
    for j in range(1, datas[0] + 1):
        union_set(datas[1], datas[j])


for i in range(1, n+1):
    if truth[find_parent(i)] == 1:
        truth[i] = 1

answer = 0
for i in range(m):
    
    flag = True
    for j in range(len(party[i])):
        if truth[party[i][j]] == 1:
            flag = False
            break
    
    if flag:
        answer += 1
        
print(answer)

