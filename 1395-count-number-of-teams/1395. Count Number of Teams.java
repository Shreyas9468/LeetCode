class Solution {
    public int numTeams(int[] rating) {
        int ans  = 0;

        int n = rating.length;
        for(int  i = 1; i < n-1; i++) {
            int ls = 0;
            int rl = 0;
            for(int  j = 0 ;j<i;j++) {
                if(rating[i]> rating[j]){
                    ls++;
                }
            }
            for(int  j = i+1;j<n;j++) {
                if(rating[i]< rating[j]){
                    rl++;
                }
            }
            
            ans +=( ls * rl);
            
            int ll = i - ls;
            int rs = n -1 - i -rl;
            
            ans += ( ll * rs );
        }
        return ans;
    }
}