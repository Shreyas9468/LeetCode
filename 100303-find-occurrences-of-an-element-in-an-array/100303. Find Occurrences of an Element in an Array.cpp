class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>st;
        for(int i =0;i<nums.size();i++){
            if(nums[i] == x){
                st.push_back(i);
            }
        }
        vector<int> ans ;
        for(auto it :queries ){
            if(it-1 >=st.size() ){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st[it-1]);
            }
        }
        return ans;
    }
};