class Solution {
public:

    int solve(vector<vector<int>>& grid, int i, int j,vector<vector<int>>&dp) {

        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // if (i >= grid.size() || j >= grid[0].size()) {
        //     return INT_MAX;
        // }

        // int down = solve(grid, i + 1, j);
        // int right = solve(grid, i, j + 1);

        // return grid[i][j] + min(down, right);

        int ans = INT_MAX;
        if(i==grid.size()-1 || j==grid[0].size()-1){
            if(i==grid.size()-1){
                ans = min(ans,grid[i][j] + solve(grid, i, j+1,dp));
            }
            if(j==grid[0].size()-1){
                ans = min(ans,grid[i][j] + solve(grid, i+1, j,dp));
            }
        }

        else{
            ans = min(ans,grid[i][j] + solve(grid, i+1, j,dp));
            ans = min(ans,grid[i][j] + solve(grid, i, j+1,dp));
            
        }
        return dp[i][j] =  ans;

    }


    int minPathSum(std::vector<std::vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        int ans = solve(grid, 0, 0,dp);
        return ans; // Placeholder return value
    }
};