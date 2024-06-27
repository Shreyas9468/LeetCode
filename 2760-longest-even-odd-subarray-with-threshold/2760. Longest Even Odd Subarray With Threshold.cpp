class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int thresold) {
        int ans=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0 and nums[i]<=thresold){
                i+=1;
                int f=1;
                while(i<nums.size()){
                    if((nums[i-1]%2)==(nums[i]%2) or nums[i]>thresold){
                        break;
                    }
                    f+=1;
                    i+=1;
                }
                i-=1;
                ans=max(ans,f);
            }
        }
        return ans;
    }
};