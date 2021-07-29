class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xFFFF
        nummax = 0x7FFF
        
        while b != 0:
            a, b = (a^b)&mask, ((a&b)<<1)&mask
        
        if a > nummax:
            a = ~(a^mask)
            
        return a
    
