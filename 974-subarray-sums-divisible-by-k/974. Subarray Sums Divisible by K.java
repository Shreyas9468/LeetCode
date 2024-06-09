import java.util.HashMap;
import java.util.*;

class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        HashMap<Integer , Integer> result = new HashMap<Integer,Integer>();
        int total = 0;
        result.put(0,1);
        int ans = 0;
        for(int i = 0;i < nums.length;i++){
            total += nums[i];
            int rem = total%k;
            if(rem < 0){
                rem +=k;
            }
            if(result.containsKey(rem)){
                ans+=result.get(rem);
            }
             result.put(rem , result.getOrDefault(rem,0)+1);
        }
        return ans;

    }
}