class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
       vector<int> ans(n-k+1 , -1);
        for(int  i = 0;i<=n-k;i++){
            int n1 = nums[i];
            bool valid = true;
            int maxele = n1;
            for(int m = i+1;m<min(i+k,n);m++){
                maxele = max(maxele , nums[m]);
                if(n1+1 != nums[m]){
                    valid = false;
                    break;
                }
                else{
                    n1 = nums[m];
                }
            }
            if(valid){
                ans[i] = maxele;
            }
        }
        return ans;

    }
};