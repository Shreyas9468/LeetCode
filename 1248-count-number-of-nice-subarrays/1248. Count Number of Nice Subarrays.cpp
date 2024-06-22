class Solution {
public:

    int solve(vector<int>& nums, int k){
        int cnt = 0;
        int i = 0;
        int  j =0;
        int ans =0;
        int  n = nums.size();
        while(j<nums.size()){
            if(nums[j]%2 !=0){
                cnt++;
            }
            while(i<n&&cnt>k){
                if(nums[i]%2!=0)
                {
                    cnt--;
                }
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int atmostk = solve(nums, k);
        int atmostk_1 = solve(nums, k-1);

        return atmostk - atmostk_1;
    }
};