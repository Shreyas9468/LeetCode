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
 bool Symmetric(TreeNode* root1,TreeNode* root2)
 {
   if(root1==NULL&&root2==NULL) return 1;
   else if(root1==NULL||root2==NULL) return 0;
  else if (root1->val==root2->val) return (Symmetric(root1->left,root2->right)&& Symmetric(root1->right,root2->left));
   else return false;
 }
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        return Symmetric(root->left,root->right);
    }
};