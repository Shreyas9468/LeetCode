class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>v;
        map<int,bool>mp;
        for(auto it : nums){
            if(mp[it]==false){
                mp[it] = true;
            }
            else{
                v.push_back(it);
            }
        }
        return v;
    }
};