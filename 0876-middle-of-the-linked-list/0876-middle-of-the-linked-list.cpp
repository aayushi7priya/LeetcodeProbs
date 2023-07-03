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
    ListNode* middleNode(ListNode* head) {
        //find total length of list 
        // n+1/2 
        ListNode* current = head;
        int n = 0;
        while(current != nullptr)
        {
            n++;
            current = current->next;
        }
        //cout<<n<<endl;
        ListNode* current1 = head;
        int i = 1;int max;
        if(n%2!=0) max = (n+1)/2;
        else max = (n+3)/2;
        while(i<max)
        {
            //cout<<i<<" pehle ka i "<<endl;
            i++;
            current1 = current1->next;
        }
        return current1;
    }
};