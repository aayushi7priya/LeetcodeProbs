/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       //wapas se fast, slow wala
        
        ListNode* slow = head;
        ListNode* fast = head;
        bool ans = false;
        while(fast!=nullptr && fast->next!= nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                ans = true;
                break;
            }
        }
        if(ans== false) return nullptr;
                                      // slow wala pehle jaha tha wahi hai
        fast = head;                 //fast ko starting point par le aaye 
        while(fast!=slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        return fast;
    }
};