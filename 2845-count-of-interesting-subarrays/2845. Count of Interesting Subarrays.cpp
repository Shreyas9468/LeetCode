#define ll long long int
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        ll ans = 0;
        ll pr = 0;
        map<ll,ll> mp;
        mp[0] =1;
        for(int i = 0;i<nums.size();i++){
            pr = (pr + (nums[i]%m == k ?1:0))%m;
            int t = (pr -k +m)%m;
            ans+=mp[t];
            mp[pr]++;
        }
        return ans;
    }
};