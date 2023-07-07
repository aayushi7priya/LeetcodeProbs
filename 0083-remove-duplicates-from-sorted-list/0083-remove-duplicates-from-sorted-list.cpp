# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        cur = head
        
        #two loops
        #first one to keep track of value of cur pointer
        # inside loop to delete all same values with cur
        while cur:
            while cur.next and cur.next.val==cur.val:
                cur.next = cur.next.next
            cur = cur.next
        return head
        