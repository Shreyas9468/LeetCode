class Solution {
    public int beautySum(String s) {
        int res=0;
        for(int i=0;i<s.length();i++){
        HashMap<Character, Integer> hs = new HashMap<>();
            for(int j=i+1;j<=s.length();j++){
        int max = Integer.MIN_VALUE,min=Integer.MAX_VALUE;
                hs.put(s.charAt(j-1),hs.getOrDefault(s.charAt(j-1),0)+1);
                if(hs.size() == 1) continue;
                else{
                    for (Map.Entry<Character, Integer> entry : hs.entrySet()){
                        max=Math.max(max,entry.getValue());
                        min=Math.min(min,entry.getValue());
                    }
                    res+=(max-min);
                }
            }
        }
        return res;
    }
}