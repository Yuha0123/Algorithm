class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        
        cnt = collections.Counter(nums)
        
        answer = cnt.most_common(1)[0][0]
        
        return answer
