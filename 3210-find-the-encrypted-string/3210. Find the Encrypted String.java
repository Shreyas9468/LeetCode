class Solution {
    public String getEncryptedString(String s, int k) {
        StringBuilder sb = new StringBuilder();
        int n = s.length();
        for(int i = 0; i < s.length(); i++) {
            char ch  = s.charAt((i+k)%n);
            sb.append(ch);
        }
        return sb.toString();
    }
}