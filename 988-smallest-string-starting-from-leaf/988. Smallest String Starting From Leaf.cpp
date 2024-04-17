class Solution {
public:
    vector<string> st;

    void solve(TreeNode* root, string ans) {
        if (root == NULL) {
            return;
        }
        ans += char('a' + root->val); // Convert int value to char
        if (root->left == NULL && root->right == NULL) {
            string a = ans;
            reverse(a.begin(), a.end());
            st.push_back(a);
            return;
        }
        solve(root->left, ans);
        solve(root->right, ans);
    }

    string smallestFromLeaf(TreeNode* root) {
        solve(root, "");
        sort(st.begin(), st.end());
        return st[0];
    }
};