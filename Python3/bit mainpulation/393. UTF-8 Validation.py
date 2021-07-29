class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        def check(size):
            if index + size > len(data):
                return False
            
            for i in range(index+1,index+size):
                if data[i] >> 6 != 0b10:
                    return False
            
            return True
            
        
        index = 0
        
        while index < len(data):
            start = data[index]
            
            if start >> 3 == 0b11110 and check(4):
                index = index + 4
            
            elif start >> 4 == 0b1110 and check(3):
                index = index + 3
            
            elif start >> 5 == 0b110 and check(2):
                index = index + 2
            
            elif start >> 7 == 0b0:
                index = index + 1
            
            else:
                return False
        
        return True
