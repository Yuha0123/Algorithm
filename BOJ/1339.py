import sys
import collections

input = sys.stdin.readline

#sys.stdin = open('./input.txt')


n = int(input())

words = [input().strip() for _ in range(n)]
cnt = collections.defaultdict(int)

for word in words:
    for i in range(len(word)):
        cnt[word[i]] += 10**(len(word) - i - 1)
        
values = sorted(cnt.values(), reverse = True)

answer = 0

factor = 9

for value in values:
    answer += factor * value
    factor -=1
    
print(answer)
