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
       //can do it o(n) space complexity
        
        unordered_set<ListNode*> mp;
        ListNode* curr = head;
        
        while(curr!=nullptr)
        {
            if(mp.find(curr)!=mp.end())
            {
                return curr;
            }
            else
            {
                mp.insert(curr);
                curr = curr->next;
            }
        }
        return nullptr;
    }
};