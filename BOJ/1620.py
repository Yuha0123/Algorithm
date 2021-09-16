import collections
import sys

input = sys.stdin.readline
#sys.stdin = open('./input.txt')

n, m = map(int, input().split())

num_to_pokemon = collections.defaultdict(str)
pokemon_to_num = collections.defaultdict(int)

for i in range(1, n + 1):
    input_pokemon = input().strip()
    
    num_to_pokemon[i] = input_pokemon
    pokemon_to_num[input_pokemon] = i
    
for i in range(m):
    question = input().strip()
    
    if question.isdigit():
        print(num_to_pokemon[int(question)])
    else:
        print(pokemon_to_num[question])
