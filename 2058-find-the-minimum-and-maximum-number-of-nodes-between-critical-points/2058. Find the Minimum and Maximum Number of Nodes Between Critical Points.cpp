class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result(2, -1); // Initialize result with [-1, -1]

        // Handle edge cases where linked list has less than 2 nodes
        if (!head || !head->next) {
            return result;
        }

        vector<int> distances;
        int position = 1;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nextNode = head->next->next;

        while (nextNode) {
            int currValue = curr->val;
            int prevValue = prev->val;
            int nextValue = nextNode->val;

            if ((currValue < prevValue && currValue < nextValue) || 
                (currValue > prevValue && currValue > nextValue)) {
                distances.push_back(position);
            }

            position++;
            prev = curr;
            curr = nextNode;
            nextNode = nextNode->next;
        }

        int size = distances.size();

        if (size >= 2) {
            int mindis = INT_MAX;
            for(int i=0; i<size-1; i++) {
              mindis = min(mindis, abs(distances[i] - distances[i+1]));
            }
            int maxdist = abs(distances[size-1] - distances[0]);
            result[0]= mindis;
            result[1]=maxdist;
        }

        return result;
    }
};
