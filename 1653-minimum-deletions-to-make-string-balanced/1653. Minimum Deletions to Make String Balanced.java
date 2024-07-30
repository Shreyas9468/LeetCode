class Solution {
    public int minimumDeletions(String s) {
        int [] ar = new int[s.length()];
        int ac = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            ar[i] = ac;
            if(s.charAt(i) == 'a'){
                ac++;
            }
        }
        
        int bc = 0;
        int res = s.length();
        for(int i = 0; i <s.length(); i++){
            res = Math.min(res, ar[i] + bc);
            if(s.charAt(i) == 'b'){
                bc++;
            }
        }
        return res;
    }
}