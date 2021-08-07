class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [0 for _ in range(len(nums) +1)]
        
        dp[1] = nums[0]
        
        for i in range(2,len(nums)+1):
            
            value = dp[i-2] + nums[i-1]
            
            if value > dp[i-1]:
                dp[i] = value
            else:
                dp[i] = dp[i-1]
                
        return dp[len(nums)]
