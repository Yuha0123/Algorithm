class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        cnt = collections.Counter()
        
        max_cnt = 0
        left = 0
        
        for right in range(len(s)):
            cnt[s[right]] += 1
            
            max_cnt = cnt.most_common(1)[0][1]
            
            if right - left - max_cnt + 1 > k:
                cnt[s[left]] -=1
                left += 1
            
            
        return right - left + 1
            
