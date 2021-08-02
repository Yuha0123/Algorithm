class Solution:
    def minWindow(self, s: str, t: str) -> str:
        def check():
            for key, value in cnt.items():
                if cur_cnt[key] < value:
                    return False
            

            return True
        
        cnt = collections.Counter(t)
        cur_cnt = collections.defaultdict(int)
        
        answer = ""
        
        left = 0
        right = 0
        
        while left <= right and right < len(s):
            
            if check() == False:
                cur_cnt[s[right]] += 1
                right += 1
            else:
                if answer == "":
                    answer = s[left:right]
                elif len(answer) > right - left:
                    answer = s[left:right]
                
                cur_cnt[s[left]] -= 1
                left += 1
            
        while check():
            if answer == "":
                answer = s[left:right]
            elif len(answer) > right - left:
                answer = s[left:right]

            cur_cnt[s[left]] -= 1
            left += 1

        return answer
