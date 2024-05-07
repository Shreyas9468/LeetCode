class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if (head->val > 4) {
            head = new ListNode(0, head);
        }
        ListNode* curr = head;
        while (curr != nullptr) {
            curr->val = (curr->val * 2) % 10;
            if (curr->next != nullptr && curr->next->val > 4) {
                curr->val += 1;
            }
            curr = curr->next;
        }
        return head;
    }
};