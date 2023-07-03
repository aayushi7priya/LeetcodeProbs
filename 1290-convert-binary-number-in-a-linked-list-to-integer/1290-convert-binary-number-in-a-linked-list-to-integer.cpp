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
    int getDecimalValue(ListNode* head) {
        ListNode* current = head;
        int num = 0;
        while(current != nullptr)
        {
            num = 2*num + current -> val;
            current = current -> next;
            
        }
        return num;
    }
};

//not so efficient , space complexity - o(n)

/*class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* current = head;
        vector<int> v;
        while(current != nullptr)
        {
            v.push_back(current->val);
            current = current -> next;
            
        }
        int n = v.size();
        int ans =0;
        for(int i=0;i<n;i++)
        {
            ans+=v[i]*(1<<(n-1-i));
        }
        return ans;
    }
};
*/