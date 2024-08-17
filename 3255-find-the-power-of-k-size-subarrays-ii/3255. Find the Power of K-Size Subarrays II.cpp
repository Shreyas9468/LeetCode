
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        if (k == 1)return nums;
        int cnt=1;
        for (int i = 1; i < (int)nums.size(); i++) {
            nums[i]==nums[i - 1]+1 ? cnt+=1 : cnt=1;
            if (i + 1 >= k) {
                cnt>=k ? ans.emplace_back(nums[i]) : ans.emplace_back(-1);
            }
        }
        return ans;
    }
};