class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> pre(maxi+2*k+2,0);
        for(int i=0;i<nums.size();i++){
            pre[nums[i]]++;
            pre[nums[i]+2*k+1]--;
        }
        int ans = pre[0];
        for(int i=1;i<maxi+2*k+2;i++){
            pre[i] = pre[i] + pre[i-1];
            ans = max(ans,pre[i]);
        }
        return ans;
    }
};