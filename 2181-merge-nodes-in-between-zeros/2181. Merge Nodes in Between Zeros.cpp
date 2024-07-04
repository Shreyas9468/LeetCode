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
    ListNode* mergeNodes(ListNode* head) {
       
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        ListNode* current = head->next; 
        int sum = 0;

        while (current != nullptr) {
            if (current->val == 0) {
               
                if (sum != 0) {
                    
                    tail->next = new ListNode(sum);
                    tail = tail->next;
                    sum = 0; 
                }
            } else {
                
                sum += current->val;
            }
            current = current->next;
        }

        return dummy.next; 
    }
};