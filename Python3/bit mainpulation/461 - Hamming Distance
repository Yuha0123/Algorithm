class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        result = x ^ y
        
        answer = 0
        
        while result > 0:
            if result & 0b1 == 1:
                answer = answer + 1
            result = result >> 1
            
        return answer
