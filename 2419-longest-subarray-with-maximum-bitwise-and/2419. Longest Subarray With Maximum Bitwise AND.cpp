class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
       
        int maxele = 0;
        for(auto it : nums){
            maxele = max(maxele,it);
        }
        int ans=1;
        int count=1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==maxele&&nums[i-1]==maxele){
                count++;
            }
            else {
                ans= max(count,ans);
                count= 1;
            }
            ans= max(count,ans);
        }
        ans= max(count,ans);
        return ans;
    }
};