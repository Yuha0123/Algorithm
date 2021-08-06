class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        if expression.isdigit():
            return [int(expression)]
        
        
        answer = []
        
        for i in range(len(expression)):
            
            if expression[i] in "+-*":
                left = self.diffWaysToCompute(expression[0:i])
                right = self.diffWaysToCompute(expression[i+1:])
                
                for num1 in left:
                    for num2 in right:
                        if expression[i] == '+':
                            result = num1 + num2
                        elif expression[i] == '-':
                            result = num1 - num2
                        else:
                            result = num1 * num2
                        
                        answer.append(result)
        return answer
