class Solution {
    public boolean judgeSquareSum(int c) {
        long l = 0;
        long r = (int) Math.sqrt(c);
        while(l<=r){
            long sum = l*l + r*r;
            if(sum ==c){
                return true;
            }

            if(sum > c){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }
}