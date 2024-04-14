class Solution {
public:

    int solve(int i,int j,vector<vector<int>>&dp){
        if(i>=dp.size()|| j>=dp[0].size()){
            return 0;
        }
        if(i==dp.size()-1 && j==dp[0].size()-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j] = solve(i+1,j,dp) + solve(i,j+1,dp);
        return dp[i][j];

    }

    int uniquePaths(int m, int n) {
        vector<vector<int> >dp(m,vector<int>(n,-1));
        int ans  = solve(0,0,dp);
        return ans; // Placeholder return value
    }
};