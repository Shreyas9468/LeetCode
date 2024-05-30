class Solution {

    void f(vector<int>nums,vector<int>&temp,vector<vector<int>>&ans,int freq[]){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=1;
                temp.push_back(nums[i]);
                f(nums,temp,ans,freq);
                freq[i]=0;
                temp.pop_back();
            }
        }
    }
     public:   
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        int freq[n];
        for(int i=0;i<nums.size();i++){
            freq[i]=0;
        }
        f(nums,temp,ans,freq);
        return ans;
    }
};