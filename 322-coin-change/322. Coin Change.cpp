class Solution {
public:
    long long solve(int amount, vector<int>& coins, vector<int>& dp) {
        if (amount == 0) {
            return 0;
        }
        if (dp[amount] != -1) {
            return dp[amount];
        }
        long long  ans = INT_MAX;
        for (auto coin : coins) {
            if (amount - coin >= 0) {
                ans = min(ans, 1LL + solve(amount - coin, coins, dp));
            }
        }
        return dp[amount] = ans;
    }
    int coinChange(std :: vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        long long ans = solve(amount, coins, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};
