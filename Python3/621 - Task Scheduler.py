class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        cnt = collections.Counter(tasks)

        answer = 0
        
        
        while True:
            interval = 0
            
            for k, _ in cnt.most_common(n+1):
                cnt[k] -= 1
                interval += 1
                answer += 1
                
            #remove the item with a value of 0
            cnt += collections.Counter()
            
            if bool(cnt) == False:
                break
            
            if interval != n + 1:
                answer += (n - interval + 1)
        
        return answer
