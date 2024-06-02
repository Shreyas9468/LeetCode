import java.util.HashMap;

class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character,Integer> hs = new HashMap<Character,Integer>();
        HashMap<Character,Integer> ht = new HashMap<Character,Integer>();
        for(int i = 0; i < s.length(); i++){
            hs.put(s.charAt(i),hs.getOrDefault(s.charAt(i),0)+1);
        }
        for(int i = 0; i < t.length(); i++){
           if(!hs.containsKey(t.charAt(i))){
               return false;
           }
           else{
               hs.put(t.charAt(i),hs.getOrDefault(t.charAt(i),0)-1);
           }
        }
        for(Integer i : hs.values()){
            if(i!=0){
                return false;
            }
        }
        return true;
        
    }
}