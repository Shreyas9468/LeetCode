class Solution {
public:
    int sumCounts(vector<int>& nums) {
        map<int,int>mp;
        int n = nums.size();
        int ans = 0;
        for(int i =0;i<nums.size();i++){
             map<int,int>mp;
            mp[nums[i]]++;
            ans +=1;
            for(int j = i+1;j<nums.size();j++){
                mp[nums[j]]++;
                ans += ((int) mp.size() * (int)mp.size());
            }
        
           
        }
        return ans;
    }
};