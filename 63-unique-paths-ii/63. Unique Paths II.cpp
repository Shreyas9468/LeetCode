class Solution {
public:

    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&obstacleGrid){
        
        if(i>=dp.size()|| j>=dp[0].size()){
            return 0;
        }
        if(obstacleGrid[i][j]==1){
            return dp[i][j]=0;
        }
        if(i==dp.size()-1 && j==dp[0].size()-1){
            return 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j] = solve(i+1,j,dp,obstacleGrid) + solve(i,j+1,dp,obstacleGrid);
        return dp[i][j];

    }

    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m  = obstacleGrid.size();
        int n = obstacleGrid[0].size();
         vector<vector<int> >dp(m,vector<int>(n,-1));
        int ans  = solve(0,0,dp,obstacleGrid);
        return ans;
    }

  
};