class Solution {
    public int maxEqualFreq(int[] nums) {
        int max=0; // gives size of hashtable
        for(int x:nums)
            if(x>max)
                max=x;
        int[] map = new int[nums.length+1]; // mapping freq -> no. of elements
        int[] a = new int[max+1]; // mapping element -> freq

        max=1; //using max for max Result
        int maxFreq=0, minFreq=Integer.MAX_VALUE, count=0;
        // count = no. of unique frequencies

        for(int i=0;i<nums.length;i++){
            int freq =  ++a[nums[i]];
            if(map[freq]++==0) // adding curr Freq
                count++;
            
            if(freq>1 && map[freq-1]--==1){ // remove prev freq
                count--; 
                if(freq-1==minFreq) // updating minFreq
                   minFreq++;
            }

            maxFreq = Math.max(maxFreq,freq); // updating maxFreq
            minFreq = Math.min(minFreq,freq); // updating minFreq
            
            // unique frequencies == 1 && (maxFreq==1 || no. of elements at maxFreq==1)
            if(count==1 && (maxFreq==1 || map[maxFreq]==1))
                max=Math.max(max,i+1);
            
            
            // unique frequencies == 2
            if(count==2){
                // element to be removed has (freq 1 || freq same as others+1)
                if(map[1]==1 || (map[maxFreq]==1 && maxFreq==minFreq+1))
                   max=Math.max(max,i+1);
            }
        }
        return max;
    }
}