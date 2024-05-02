class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;;
        int maxval =-1;
        while(i<j){
            int num1 = (nums[i]);
            int num2 = (nums[j]);
            if(num1+num2==0){
                maxval = max(maxval,abs(nums[j]));
                i++;
                j--;
            }
           else if(num1 + num2 <0){
                i++;
            }
            else{
                j--;
            }
        }
        return maxval;
    }
};