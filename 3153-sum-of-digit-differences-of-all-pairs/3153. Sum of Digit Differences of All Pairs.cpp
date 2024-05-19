#define ll long long

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        map<pair<int,int>,long long>mp;
        for(auto it : nums){
            int index =0;
            int x = it;
            while(x){
                mp[{x%10,index}]++;
                index++;
                x/=10;
            }
            
        }
        int digit = to_string(nums[0]).length();
        ll ans = 1ll* (nums.size() * (nums.size()-1))/2*digit;
        for(auto it : mp){
            ll j = it.second;
            ans -= (j*(j-1)/2);
        }
        return ans;

    }
};