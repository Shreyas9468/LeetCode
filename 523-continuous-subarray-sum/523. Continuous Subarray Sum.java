import java.util.HashMap;

class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int sum = 0;
        HashMap<Integer , Integer> hm  = new HashMap<Integer, Integer>();
        hm.put(0,-1);
        for(int i = 0; i < nums.length; i++){
            sum+=nums[i];
            int rem = sum %k;
            if(hm.containsKey(rem)){
                int ind = hm.get(rem);
                if(i - ind >=2){
                    return true;
                }
            }
            else{
                hm.put(rem,i);
            }
        }
        return false;
    }
}