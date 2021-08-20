import sys
import collections

input = sys.stdin.readline

#sys.stdin = open('./input.txt')


n, s = map(int, input().split())

nums = list(map(int,input().split()))

total = 0
left = 0
right = 0
answer = 1000000

while right <= n:
    if total < s:
        if right < n:
            total += nums[right]
        right += 1
    else:
        total -= nums[left]
        left += 1
    
    if total >= s:
        answer = min(answer, right - left)

if answer == 1000000:
    print(0)
else:
    print(answer)
