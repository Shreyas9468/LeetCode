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

    int sumNumbers(TreeNode* root) {
        // Your implementation of sumNumbers function goes here
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
        
    }
    
    void dfs(TreeNode* node, int curr, int& sum) {
        if (node == nullptr) return;
        curr = curr * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            sum += curr;
            return;
        }
        dfs(node->left, curr, sum);
        dfs(node->right, curr, sum);
    }
};