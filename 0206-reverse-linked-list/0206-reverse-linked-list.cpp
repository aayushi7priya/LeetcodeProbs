class Solution {
public:
    ListNode* head1;
    void reverseHelper(ListNode* prev, ListNode* curr) {
        if (curr == nullptr) {
            head1 = prev;
            return;
        }

        ListNode* next1 = curr->next;
        curr->next = prev;            // Update pointers to reverse the connection between current and next node
        reverseHelper(curr, next1);   // Recursive call to reverse the sublist starting from next node
    }

    ListNode* reverseList(ListNode* head) {
        head1 = head;
        reverseHelper(nullptr, head1);
        return head1;
    }
};
