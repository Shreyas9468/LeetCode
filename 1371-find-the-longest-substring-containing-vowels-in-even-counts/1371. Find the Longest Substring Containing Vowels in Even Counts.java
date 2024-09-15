import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public int findTheLongestSubstring(String s) {
        HashMap<Character,Integer> map = new HashMap<Character,Integer>();
        map.put('a',1);
        map.put('e',2);
        map.put('i',4);
        map.put('o',8);
        map.put('u',16);
        int seen [] =  new int[32];
        Arrays.fill(seen,-1);
        int mask =0;
        int maxlen = 0;
        for(int i = 0;i<s.length();i++){
            mask = mask ^ (map.get(s.charAt(i))==null ? 0 : map.get(s.charAt(i)));
            if(mask !=0 && seen[mask] == -1){
                seen[mask] = i;
            }
            maxlen  = Math.max(maxlen,i - seen[mask]);
        }
        return maxlen;

    }
}