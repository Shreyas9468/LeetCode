class Solution {
    public long maxAlternatingSum(int[] nums) {
        long res = nums[0];
        for (int i = 1; i < nums.length; i++) {
            res += Math.max(nums[i] - nums[i - 1], 0);
        }
        return res;
    }
}