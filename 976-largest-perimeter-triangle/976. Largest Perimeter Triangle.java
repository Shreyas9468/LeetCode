class Solution {
    public int largestPerimeter(int[] nums) {
    Arrays.sort(nums);
    for(int i=nums.length-1;i>1;i--){
        int a = nums[i-2];
        int b = nums[i-1];
        int c = nums[i];
			int s = a + b + c;
        if(a+b>c)
		{
            return s;
        }
    }
    return 0;
    }
}