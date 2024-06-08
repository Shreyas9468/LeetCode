class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // ... (implementation of the checkSubarraySum function)
        if(nums.size()<=1){
            return 0;
        }
        unordered_map<int,int>remindercheck ;
        remindercheck[0]=-1;
        long long int sum =0;
        for(int i =0;i<nums.size();i++){
            sum +=nums[i];
            int rem = sum%k;
            if(remindercheck.count(rem)){
                int previndx = remindercheck[rem];
                if(i-previndx>=2){
                    return true;
                }
            }            
            else{
                remindercheck[rem] =i;
            }

        }
        return false;

        

    }
};