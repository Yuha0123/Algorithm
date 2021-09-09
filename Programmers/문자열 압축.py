def solution(s):
    
    
    n = len(s)
    k = n//2
    answer = n
    
    for i in range(k,0,-1):
        
        new_len = 0
        pos = 0
        
        while pos < n:
            if n - pos < 2*i:
                new_len += n - pos
                break
            
            string = s[pos: pos+i]
            cnt = 1
            
            x = pos + i
            while x < n and s[x] == string[x % i]:
                
                if x % i == i - 1:
                    cnt += 1
                x += 1
            
            pos += cnt * i
            
            if cnt == 1:
                new_len += i
            else: 
                new_len += len(str(cnt)) + i
            
        answer = min(answer, new_len)
    
    
    return answer
