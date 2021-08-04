import queue
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        
        pq = queue.PriorityQueue()
        
        for p in people:
            pq.put((-p[0],p[1]))
            
        answer = []
        
        while pq.empty() == False:
            p = pq.get()
            
            answer.insert(p[1], [-p[0],p[1]])
            
        return answer
