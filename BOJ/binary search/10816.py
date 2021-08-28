import sys
import bisect

input = sys.stdin.readline
#sys.stdin = open('./input.txt')

n = int(input())

nums = list(map(int, input().split()))

m = int(input())

datas = list(map(int, input().split()))

nums.sort()

for data in datas:
    right = bisect.bisect_right(nums, data)
    left = bisect.bisect_left(nums, data)
    
    print(right - left, end = " ")
