import collections
def solution(orders, course):
    answer = []
    cnt = collections.defaultdict(int)
    
    def DFS(s, c, x):
        if len(c) in course:
            cnt[''.join(c)] += 1
            
        if x >= len(s):
            return
            
        for i in range(x, len(s)):
            c.append(s[i])
            DFS(s,c,i+1)
            c.pop()
        
    for order in orders:
        order = ''.join(sorted(order))
        DFS(order, [], 0)
    
    for num in course:
        arr = []
        max_len = 0
        
        for key, value in cnt.items():
            if len(key) == num and value >= 2:
                arr.append((value, key))
                max_len = max(max_len, value)
                
        arr.sort(reverse = True)
        
        for value, key in arr:
            if max_len == value:
                answer.append(key)
            else:
                break
        
    answer.sort()    
    
    return answer
