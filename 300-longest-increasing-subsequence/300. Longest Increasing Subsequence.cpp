class Solution {
public:
    int lis(int i , vector<int> &a ,vector<int>&dp){
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans  = 1;
    for(int j =0;j<i;j++){
        if(a[i] > a[j]){
            ans = max(ans , 1 + lis(j , a , dp));
        }
    }
    return dp[i] = ans;
}
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n , -1);
        int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans, lis(i , a ,dp));
    }
    return ans;
    }
};

