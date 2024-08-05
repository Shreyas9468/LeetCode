class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans=0;
        vector<int>v(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            int cnt=0, k=i;
            while(!v[k]){
                v[k]=1;
                cnt++;
                k=nums[k];
            }
            ans=max(ans, cnt);
        }
        return ans;
    }
};