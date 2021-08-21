import sys

input = sys.stdin.readline
#sys.stdin = open('./input.txt')

n, m, k = map(int, input().split())

pivot = 1 << 20
tree = [1 for _ in range(pivot*2)]
mod = 1000000007

def init_tree():
    for i in range(pivot - 1, 0 , -1):
        tree[i] = (tree[i*2] * tree[i*2 + 1]) % mod


def update(pos, val):
    
    pos += pivot
    tree[pos] = val
    pos = pos//2
    
    while pos:
        tree[pos] = (tree[pos*2] * tree[pos*2 + 1]) % mod
        pos = pos//2
    

def query(l, r):
    answer = 1
    
    l += pivot
    r += pivot
    
    while l <= r:
        if l % 2 == 1:
            answer = (answer * tree[l])%mod
            l += 1
        if r % 2 == 0:
            answer = (answer * tree[r])%mod
            r -= 1
            
        l = l // 2
        r = r // 2
    
    return answer



for i in range(n):
    num = int(input())
    tree[i + pivot] = num
    

init_tree()


for _ in range(m+k):
    cmd = list(map(int, input().split()))
        
    if cmd[0] == 1:
        update(cmd[1] -1 , cmd[2])
    else:
        print(query(cmd[1] - 1 , cmd[2] - 1))
