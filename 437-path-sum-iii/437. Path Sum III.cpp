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
    int total =0;
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        findpathsum(targetSum,0,root);
        pathSum(root->left ,targetSum);
        pathSum(root->right ,targetSum);

        return total;
    }

    void findpathsum(long long target , long long currsum , TreeNode * root){
        if(root==NULL){
            return ;
        }
        currsum += root->val;

        if(currsum == target){
            total++;
        }
        findpathsum(target , currsum , root->left);
        findpathsum(target , currsum , root->right);
    }
};