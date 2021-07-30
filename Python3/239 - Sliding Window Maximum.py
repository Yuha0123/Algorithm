class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        answer = []
        
        queue = collections.deque()
        
        for i in range(len(nums)):
            if queue and i - queue[0] == k:
                queue.popleft()
                
            while queue:
                if nums[queue[-1]] < nums[i]:
                    queue.pop()
                else:
                    break
            
            queue.append(i)
            
            if i >= k - 1:
                answer.append(nums[queue[0]])
            
        
        return answer
