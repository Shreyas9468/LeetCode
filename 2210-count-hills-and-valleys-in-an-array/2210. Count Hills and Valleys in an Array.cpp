class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        int count=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]) v.push_back(nums[i]);
        }
        if(v.size()==0 || v.size()==1) return 0;
        if(v[v.size()-1]!=nums[n-1]) v.push_back(nums[n-1]);
        for(int i=1;i<v.size()-1;i++){
            if((v[i]>v[i-1])&&(v[i]>v[i+1]))//to check hill
            {
                count++;
            }
            else if((v[i]<v[i-1]) && (v[i]<v[i+1])){//To check valley
                count++;
            }
        }
        return count;
    }
};