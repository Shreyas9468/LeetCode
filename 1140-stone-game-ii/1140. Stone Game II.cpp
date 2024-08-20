class Solution {
public:
    int n;
    int dp[2][101][101];
    int alice(int isBob, int i, int m, vector<int>& piles){
        if (i == n) return 0;
        if (dp[isBob][i][m]!=-1) return dp[isBob][i][m];
        int stones =(isBob == 0)? 0: INT_MAX;
        int sum = 0, xN= min(2*m, n-i);
        for (int x = 1; x <= xN; x++) {
            sum += piles[i+x-1];
            int m2=max(m, x);
            if (isBob) 
                stones=min(stones, alice(0, i+x, m2, piles));
            else 
                stones=max(stones, sum+alice(1, i+x, m2, piles));                       
        }
        return dp[isBob][i][m]=stones;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        return alice(0, 0, 1,  piles);
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();