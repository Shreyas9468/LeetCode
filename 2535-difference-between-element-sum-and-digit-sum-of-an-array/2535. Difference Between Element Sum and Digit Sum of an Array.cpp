class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int ele_sum = accumulate(nums.begin(),nums.end(),0);
        int dig_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            int num = nums[i];
            while(num!=0)
            {
                dig_sum=dig_sum+(num%10);
                num = num/10;

            }
        }
        return abs(ele_sum-dig_sum);
    }
};