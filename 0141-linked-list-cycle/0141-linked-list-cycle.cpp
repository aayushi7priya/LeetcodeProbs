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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>mp;
        bool ans = false;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            if(mp.find(curr)!=mp.end())
            {
                ans = true;
                break;
            }
            else {
                mp.insert(curr);
                curr = curr->next;
            }
        }
        return ans;
    }
};