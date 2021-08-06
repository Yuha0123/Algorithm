class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        elif n == 1:
            return 1
        
        f0 = 0
        f1 = 1
        
        for i in range(n - 1):
            f2 = f1 + f0
            
            f0 =  f1
            f1 = f2
        
        return f2
        
