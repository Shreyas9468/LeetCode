class Solution {
public:
    int countTriplets(vector<int>& nums) {
        map<int , int> mp;
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();i++){
            for(int j = 0;j<nums.size();j++){
                int val = nums[i] & nums[j];
                mp[val]++;
            }
        }
        int ans = 0;
        for(auto it : mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        for(int i = 0;i<nums.size();i++){
            for(auto it : mp){
                if((it.first & nums[i]) ==0){
                    ans += it.second;
                }
            }
        }
        return ans;
    }
};