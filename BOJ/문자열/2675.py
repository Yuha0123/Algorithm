import sys
import collections

input = sys.stdin.readline
#sys.stdin = open('./input.txt')

t = int(input())

for _ in range(t):
    n, s = map(str, input().split())
    
    n = int(n)
    s = s.rstrip()
    
    answer = ""
    
    for c in s:
        for _ in range(n):
            answer = answer + c
            
    print(answer)
