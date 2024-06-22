import java.util.*;


class Solution {
    public int countDistinct(int[] nums, int k, int p) {
        Set<String> set = new HashSet<String>();

        for(int i = 0; i < nums.length; i++){
            StringBuilder sb = new StringBuilder();
            int cnt = 0;
            for(int j = i ;j < nums.length;j++){
                if(nums[j] % p ==0){
                    cnt++;
                }
                if(cnt > k){
                    break;
                }
                sb.append(nums[j]+"_");
                set.add(sb.toString());
            }
        }
       return set.size();
    }
}