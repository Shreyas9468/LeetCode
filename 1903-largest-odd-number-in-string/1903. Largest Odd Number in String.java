class Solution {
    public String largestOddNumber(String num) {
        String ans ="";
        int  n = num.length();
        for(int i = n-1; i >=0; i--){
           char c = num.charAt(i);
           int num2 = c - '0';
           if(num2%2!=0){
               return num.substring(0,i+1);
           }
        }
        return "";
    }
}