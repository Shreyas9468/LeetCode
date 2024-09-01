class Solution {
    public boolean checkTwoChessboards(String coordinate1, String coordinate2) {
        int f1= (coordinate1.charAt(0)-'a') + (coordinate1.charAt(1)-'0');
        int f2 = (coordinate2.charAt(0)-'a') + (coordinate2.charAt(1)-'0');
        if((f1%2==0 && f2%2==0)||(f1%2!=0 && f2%2!=0)){
            return true;
        }
        return false;
    }
}