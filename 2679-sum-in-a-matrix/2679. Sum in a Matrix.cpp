class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int ans = 0;
        int i,j,x,m=nums.size(),n = nums[0].size();
        for(auto &i: nums){
            sort(i.begin(),i.end());
        }
        for(j = 0; j < n; j++){
            x = 0;
            for(i = 0; i < m; i++){
                x = max(x,nums[i][j]);
            }
            ans += x;
        }
        return ans;
    }
};