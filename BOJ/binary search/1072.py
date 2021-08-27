import sys

input = sys.stdin.readline
#sys.stdin = open('./input.txt')

x, y= map(int, input().split())

z = y * 100 // x

if z >= 99:
    print("-1")

else:
    l = 1
    r = 1000000000
    
    while l<=r:
        mid = (l + r)//2
        
        n = ((y + mid) * 100)//(x + mid)
        
        if n > z:
            r = mid - 1
        else:
            l = mid + 1
    
    print(l)
