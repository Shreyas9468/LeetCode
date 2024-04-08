class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        // Your logic for finding the length of the longest increasing subsequence goes here
        // Return the result    
        int maxlength=INT_MIN;
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            maxlength=max(maxlength,dp[i]);
        }
        return maxlength;
    }
};
