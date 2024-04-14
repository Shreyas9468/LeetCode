class Solution {
public:

    int solve(int i , vector<int>&dp){
        if(i<=1){
            return i;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i] = solve(i-1,dp) + solve(i-2,dp);
    }

    int fib(int n) {
        vector<int>dp(n+1,-1);
        int ans = solve(n,dp);
        return ans;
    }
};