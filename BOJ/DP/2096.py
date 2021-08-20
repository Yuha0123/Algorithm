import sys
import collections

input = sys.stdin.readline

#sys.stdin = open('./input.txt')

n = int(input())

line =  list(map(int, input().split()))

min_list = line[:]
max_list = line[:]


for i in range(1, n):
    line =  list(map(int, input().split()))
    
    temp = min_list[:]
    min_list[0] = min(temp[0], temp[1]) + line[0]
    min_list[1] = min(temp[0], temp[1], temp[2]) + line[1]
    min_list[2] = min(temp[1], temp[2]) + line[2]
    
    temp = max_list[:]
    max_list[0] = max(temp[0], temp[1]) + line[0]
    max_list[1] = max(temp[0], temp[1], temp[2]) + line[1]
    max_list[2] = max(temp[1], temp[2]) + line[2]


print(max(max_list), min(min_list))
