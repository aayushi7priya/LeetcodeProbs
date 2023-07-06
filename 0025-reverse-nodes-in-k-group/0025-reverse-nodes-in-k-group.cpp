/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   
ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
    
    // Count the number of nodes in the current group
    int count = 0;
    ListNode* temp = head;
    while (temp && count < k) {
        temp = temp->next;
        count++;
    }
    
    // Base case: if the remaining nodes are less than k, no reversal needed
    if (count < k)
        return head;
    
    // Reverse the nodes within the group
    count = 0;
    while (current && count < k) {
        next = current->next;    //get next pointer
        current->next = prev;    
        prev = current;         //update value
        current = next;         
        count++;
    }
    
    // Recursively reverse the rest of the list and link it to the reversed group
    if (next)      //this next is from where we need to reverse now
        head->next = reverseKGroup(next, k);
    
    return prev;
};
};
