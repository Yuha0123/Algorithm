import sys
import collections

input = sys.stdin.readline
#sys.stdin = open('./input.txt')

t = int(input())

nums = list(map(int, input().split()))

for num in nums:
    
    div = set()
    
    for i in range(1, int(num**(1/2)) + 1):
        if num % i == 0:
            div.add(i)
            div.add(num//i)

    s = sum(div) - num
    
    if s == num:
        print("Perfect")
    elif s > num:
        print("Abundant")
    else:
        print("Deficient")
