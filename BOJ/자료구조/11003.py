import sys
import collections

input = sys.stdin.readline

#sys.stdin = open('./input.txt')


n, l = map(int, input().split())

nums = list(map(int,input().split()))
answer = []

queue = collections.deque()

for i in range(n):
    if queue and i - queue[0] == l:
        queue.popleft()
    
    while queue and nums[queue[-1]] > nums[i]:
        queue.pop()

    queue.append(i)
    
    answer.append(queue[0])
    
for i in range(n):
    print(nums[answer[i]], end=" ")
