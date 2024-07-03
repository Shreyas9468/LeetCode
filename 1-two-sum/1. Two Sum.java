import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> sum = new HashMap<Integer, Integer>();
        for(int i =0;i<nums.length;i++){
            int req = target - nums[i];
            if(sum.containsKey(req)){
                return new int[]{sum.get(req), i};
            }
            else{
                sum.put(nums[i],i);
            }
        }
        return new int[]{-1,-1};
    }
}