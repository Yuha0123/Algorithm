import sys

input = sys.stdin.readline
#sys.stdin = open('./input.txt')

n, m = map(int, input().split())
cards = list(map(int, input().split()))


def BlackJack():
    answer = 0
    
    for i in range(n):
        for j in range(i + 1,n):
            for k in range(j + 1,n):
                s = cards[i] + cards[j] + cards[k]
                
                if s == m:
                    return s
                
                if s > answer and s <= m:
                    answer = s
    return answer



print(BlackJack())
