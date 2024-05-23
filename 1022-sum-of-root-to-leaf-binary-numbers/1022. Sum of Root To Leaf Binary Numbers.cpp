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

    void dfs(vector<string>&ans , string s , TreeNode * root){
        // if(root->left ==NULL) return ;
        // if(root->right ==NULL) return;
        if(!root) return;
        if(root->left ==NULL && root->right == NULL){
             s.push_back(root->val+'0');
            ans.push_back(s);
            return ;
        }
        s.push_back(root->val+'0');
        dfs(ans, s,root->left);
        // s.pop_back();
        dfs(ans , s , root->right);
        
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string>ans;
        dfs(ans , "" , root);
        int sum = 0;
        for(auto it : ans){
            int number =0;
            number = stoi(it, nullptr, 2);
            sum+=number;
        }
        return sum;
    }
};