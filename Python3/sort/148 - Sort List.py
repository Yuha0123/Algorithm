
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        return self.mergeSort(head)
        
        
    
    def mergeSort(self, head:ListNode):
        if head is None or head.next is None:
            return head
        
        #partition
        slow = head
        fast = head
        half = None
        
        while fast and fast.next:
            slow, fast, half = slow.next, fast.next.next, slow
        
        half.next = None
        
        return self.merge(self.mergeSort(head), self.mergeSort(slow))
    
    def merge(self, list1, list2):
        if list1 and list2:
            if list1.val > list2.val:
                list1, list2 = list2, list1
                
            list1.next = self.merge(list1.next, list2)
            
        return list1 or list2
