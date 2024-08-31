class Solution {
    public String stringHash(String s, int k) {
        StringBuilder sb = new StringBuilder();
        int substrings = s.length()/k;
        int i = 0;
        while (substrings>0){
            String s2 = s.substring(i,i+k);
            int sum = 0;
            for (int j = 0; j < s2.length(); j++){
                sum+= s2.charAt(j)-'a';
            }
            char ch = (char) ((sum%26)+'a');
            sb.append(ch);
            i+=k;
            substrings--;
        }
        return sb.toString();

    }
}