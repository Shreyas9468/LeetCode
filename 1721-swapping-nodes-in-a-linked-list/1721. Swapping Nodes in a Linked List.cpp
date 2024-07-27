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

    int Len(ListNode*head){
        if(!head) return 0;
        return 1+ Len(head->next);
    }

    ListNode* swapNodes(ListNode* head, int k) {
        //case 1
        if(!head || !head->next) return head;

        int len = Len(head);
        int lpos = k;
        int rpos = len - k + 1;

        if(rpos < lpos){
            //to maintain the nomenclature of npos and rpos
            swap(rpos , lpos);
        }

        //case 2
        if(lpos == rpos) return head;

        //case 3
        if(len == 2){
            ListNode* nextNode = head->next;
            nextNode->next = head;
            head->next = nullptr;
            head = nextNode;
            return head;
        }

        //case 4
        if(lpos == 1){
            //k ==1 or k == n -> we have handled the nomenclature
            ListNode *lp = 0;
            ListNode *rp = head;
            ListNode *ln = head;

            for(int i = 0; i<rpos-2 ;i++)
                rp = rp->next;
            
            ListNode *rn = rp->next;
            ListNode *rsave = rn->next;

            rn->next = ln->next;
            rp->next = ln;
            ln->next = rsave;
            head = rn;
            return head;
        }

        //case 5   
        int noOfNodesBetweenSwapNodes = rpos - lpos - 1;
        if(noOfNodesBetweenSwapNodes == 0){
            ListNode *lp = head;
            for(int i = 0; i<lpos-2 ;i++){
                lp = lp->next;
            }
            ListNode* ln =lp->next;

            ListNode*rp = head;
            for(int i = 0 ;i<rpos- 2;i++){
                rp = rp->next;
            }
            ListNode *rn = rp->next;
            ListNode *rsave = rn->next;

            lp->next = rp->next;
            rn->next = rp;
            rp->next = rsave;
            return head;
        }
        else{
            //no of nodes btw swap nodes >= 1
            //case 6'
              ListNode *lp = head;
            for(int i = 0; i<lpos-2 ;i++){
                lp = lp->next;
            }
            ListNode* ln =lp->next;

            ListNode*rp = head;
            for(int i = 0 ;i<rpos- 2;i++){
                rp = rp->next;
            }
            ListNode *rn = rp->next;
            ListNode *rsave = rn->next;

            lp->next = rn;
            rn->next = ln->next;
            rp->next = ln;
            ln->next = rsave;
            return head;
        }
    }
};