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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to check if the remaining list matches a path from the current tree node
    bool dfs(ListNode* head, TreeNode* root) {
        if (!head) return true;  // If we have traversed the entire list, return true
        if (!root) return false; // If tree node is null but list is not finished, return false
        
        // If current values match, try to match the rest of the list in left or right subtree
        if (head->val == root->val) {
            return dfs(head->next, root->left) || dfs(head->next, root->right);
        }
        
        return false; // If values do not match
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false; // If tree is null, no path exists
        
        // Try to match from the current root, or recursively check in the left or right subtrees
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
