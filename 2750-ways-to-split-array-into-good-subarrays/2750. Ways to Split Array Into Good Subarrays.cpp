int speedup = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long ans = 0;
        int oc = 0;
        int zc = 0;
        int n = nums.size();
        int mod = 1e9+7;
        for(int i =0;i<n;i++){
            if(nums[i] == 0){
                zc++;
            }
            else{
                oc++;
                if(oc == 1){
                    ans = 1;
                }
                else{
                    ans = (ans*(zc+1)%mod)%mod;
                }
                zc = 0;
            }
        }
        return (int) ans;
    }
};