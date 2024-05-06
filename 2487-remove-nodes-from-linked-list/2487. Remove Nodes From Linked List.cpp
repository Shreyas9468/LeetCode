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
    ListNode* removeNodes(ListNode* head) {
        vector<int>vt;
        ListNode * temp = head;
        while(temp){
            vt.push_back(temp->val);
            temp = temp->next;
        }
        stack<int>st;
        st.push(vt[0]);
        for(int i=1;i<vt.size();i++){
            while(!st.empty()&&st.top()<vt[i]){
                st.pop();
            }
            st.push(vt[i]);
        }
         ListNode* newHead = nullptr;
        ListNode* current = nullptr;
        while (!st.empty()) {
            ListNode* newNode = new ListNode(st.top());
            st.pop();
            newNode->next = current;
            current = newNode;
        }
        return current;
    }
};