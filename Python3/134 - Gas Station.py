class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        
        if sum(gas) < sum(cost):
            return -1
        
        answer = 0
        remain = 0
        
        for i in range(len(gas)):
            #not start point
            if remain + gas[i] - cost[i] < 0:
                answer = i + 1
                remain = 0
            else:
                remain += gas[i] - cost[i]
        
            
        return answer
