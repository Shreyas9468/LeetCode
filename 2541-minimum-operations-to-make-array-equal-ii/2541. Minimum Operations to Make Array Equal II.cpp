class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k==0){
            for(int  i = 0;i<nums1.size();i++){
                if(nums1[i] - nums2[i] != 0){
                    return -1;
                }
            }
            return 0;
        }
        long long int inr = 0;
        long long int dcr = 0;
        for(int i = 0;i<nums1.size();i++){
            int diff = abs(nums1[i] - nums2[i]);
            if(diff==0) continue;
            if(nums1[i] > nums2[i]){
                
                 if(diff%k!=0) return -1;
                 else{
                    dcr += diff/k;
                 }
            }
            else {
                 if(diff%k!=0) return -1;
                 else{
                    inr += diff/k;
                 }
            }
        }

        return abs(dcr-inr) ==0 ? (inr + dcr) / 2:-1;
    }
};