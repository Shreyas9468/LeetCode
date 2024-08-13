class Solution {
public:
    vector<vector<int>> ans; // Store unique combinations
    vector<int> v; // Temporary vector to store current combination
    
    void solve(int t, vector<int>& candidates, int i) {
        if (t == 0) {
            ans.push_back(v); // Add the current combination to the result
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                // Skip duplicates
                continue;
            }

            if (candidates[j] > t) {
                // If the current candidate exceeds the target, no need to proceed further
                break;
            }

            v.push_back(candidates[j]);
            solve(t - candidates[j], candidates, j + 1); // Recur for the next element
            v.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates and make pruning easier

        // Start solving
        solve(target, candidates, 0);

        return ans;
    }
};
