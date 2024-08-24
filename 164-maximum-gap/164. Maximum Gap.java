class Solution {
    public int maximumGap(int[] nums) {
        if(nums.length==1)return 0;
        Arrays.sort(nums);
        int max_sum=0;
        // int pre=0;
        for( int i=0; i<nums.length-1; i++)
        {
            if(nums[i+1]-nums[i]>max_sum)
            {
                max_sum=nums[i+1]-nums[i];
            }
        }
        return max_sum;
    }
}