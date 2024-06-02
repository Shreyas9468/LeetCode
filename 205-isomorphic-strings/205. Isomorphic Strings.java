import java.util.HashMap;

class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character>  hs = new HashMap<Character, Character>();
        HashMap<Character,Character> ht = new HashMap<Character, Character>();
        for(int i = 0; i < s.length(); i++){
            Character cs = s.charAt(i);
            Character ct = t.charAt(i);
            if(hs.containsKey(cs)){
                if(!hs.get(cs).equals(ct)){
                    return false;
                }
            }
            else{
                hs.put(cs, ct);
            }

            if(ht.containsKey(ct)){
                if(!ht.get(ct).equals(cs)){
                    return false;
                }
            }
            else{
                ht.put(ct, cs);
            }
        }
        return true;
    }
}