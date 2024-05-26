class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long cnt =  0;
        map<long long int,long long int>mp;
        for(auto it : nums2){
            mp[it]++;
        }
        for(auto val : nums1){
            if(val%k==0){
                long long int ran = val/k;
                for(int i = 1 ;i*i<= ran ;i++){
                    if(ran%i == 0){
                        cnt+=  mp[i];
                        if(i != ran/i){
                            cnt+= mp[ran/i];
                        }
                    }
                }
            }
        }
        return cnt;
    }
};