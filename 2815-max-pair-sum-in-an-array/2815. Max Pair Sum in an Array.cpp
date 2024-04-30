class Solution {
public:
    int maxdigit(int n){
        int digit =0;
        while(n>0){
            digit = max(digit , n%10);
            n/=10;
        }
        return digit;
    }
    int maxSum(vector<int>& nums) {
        vector<pair<int,int>>vp;
        for(int i =0;i<nums.size();i++){
            int digit = maxdigit(nums[i]);
            vp.push_back(make_pair(nums[i] , digit));
        }
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                if(vp[i].second == vp[j].second){
                    sum = max(sum , vp[i].first + vp[j].first);
                }
            }
        }
        return sum == 0 ? -1 : sum;
    }
};