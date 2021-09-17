import sys
import collections

input = sys.stdin.readline
#sys.stdin = open('./input.txt')

n, m = map(int, input().split())
lamps = list(list(input().strip() for _ in range(n)))

k = int(input())

status = list(list(0 for _ in range(m)) for _ in range(n))



col = []

for i in range(n):
    temp = []
    for j in range(m):
        if lamps[i][j] == '0':
            temp.append(j)
        
    col.append(tuple(temp))

counter = collections.Counter(col)

answer = 0

for key, value in counter.items():
    l = len(key)
    if k >= l and k%2 == l%2:
        answer = max(answer, value)

print(answer)
