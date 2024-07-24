class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>ans;
        for(int i = 0;i<n;i++){
            int num = nums[i];
            int p = 1;
            int ne = 0;
            if(num==0){
                ne = mapping[0];
            }
            while(num>0){
                int e = num%10;
                ne+= p * mapping[e];
                num/=10;
                p*=10;
            }
            ans.push_back({ne , i});
        }
        sort(ans.begin(),ans.end());
        vector<int>res;

        for(auto it : ans){
            res.push_back(nums[it.second]);
        }

        return res;
    }
};