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

    int sum = INT_MIN;
    int solve(TreeNode * root){
        if(root==nullptr) return 0;
        int  lh = solve(root->left);
        int rh = solve(root->right);
        lh = max(0,lh);
        rh = max(rh ,0);
        sum = max(sum , lh +rh + root->val);
        return max(lh , rh) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int ans = solve(root);
        return sum;
    }
};