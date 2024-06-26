class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0, n = nums.size();
        int maxi = nums.back();
        if(maxi < nums.size()) result++;
        if(nums[0] != 0 and maxi < nums.size()) result++;
        for(int i=0;i<n-1;i++) {
            if(i+1 > nums[i] and i+1 < nums.back() and i+1 < nums[i+1]) result++;
        }
        return result;
    }
};