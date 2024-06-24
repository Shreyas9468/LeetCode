class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int [] res = new int[n];
        for(int i = 0;i< bookings.length;i++){
            int s = bookings[i][0];
            int e = bookings[i][1];
            int r = bookings[i][2];
            res[s-1] += r;
            if(e<n){
                res[e] -=r;
            }
        }
        for(int i =1;i<n;i++){
            res[i] += res[i-1];
        }
        return res;
    }
}