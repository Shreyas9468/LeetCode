class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int ans = 0;
       for(int i = 1;i<nums.size();i++){
        if(nums[i]<=nums[i-1]){
            int add = nums[i-1]-nums[i]+1;
            ans += (add);
            nums[i] = nums[i] + (add);
        }
       }
        return ans;

    }
};