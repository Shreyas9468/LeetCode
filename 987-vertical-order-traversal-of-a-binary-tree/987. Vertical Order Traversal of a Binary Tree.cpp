class Solution {
public:
    void solve(TreeNode* root, map<int, map<int, vector<int>>>& mp, int row, int col) {
        if (root == nullptr) return;

        // Store the node value at the correct position
        mp[col][row].push_back(root->val);

        // Traverse the left subtree
        solve(root->left, mp, row + 1, col - 1);

        // Traverse the right subtree
        solve(root->right, mp, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to hold the nodes according to their vertical and horizontal positions
        map<int, map<int, vector<int>>> mp;
        solve(root, mp, 0, 0);

        vector<vector<int>> ans;

        for (auto& col : mp) {
            vector<int> colVals;
            for (auto& row : col.second) {
                // Sort the values at each position to get the required order
                sort(row.second.begin(), row.second.end());
                colVals.insert(colVals.end(), row.second.begin(), row.second.end());
            }
            ans.push_back(colVals);
        }

        return ans;
    }
};