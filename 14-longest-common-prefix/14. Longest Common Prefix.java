class Solution {
    public String longestCommonPrefix(String[] strs) {
        int len = 2000;
        for(String str : strs) {
            len = Math.min(len , str.length());
        }
        for(int i = len;i>=0;i--) {
            String s = strs[0].substring(0,i);
            //System.out.println(s);
            boolean notfound = false;
            for(int j = 1 ;j<strs.length ;j++) {
                String b = strs[j].substring(0,i);
               // System.out.println(b);
                if(!b.equals(s)) {
                    notfound = true;
                }
            }
            if(!notfound){
                return s;
            }
        }
        return "";
    }
}