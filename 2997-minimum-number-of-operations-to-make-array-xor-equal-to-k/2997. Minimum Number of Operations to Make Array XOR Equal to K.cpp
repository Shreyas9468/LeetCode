class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int>bits(32,0);
        
        for(auto it:nums)
        {
            for(int i=0;i<32;i++)
            {
                if(it&(1<<i))bits[i]++;
            }
        }
        
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if(k&(1<<i))
            {
                ans+=bits[i]%2==0;
            }
            else ans+=bits[i]%2==1;
        }
        return ans;
    }
};