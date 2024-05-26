class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        HashSet<Integer> hs=new HashSet<>();
        for(Integer it:arr){
            hs.add(it);
        }
        List<List<Integer>> ans=new ArrayList<>();
        Arrays.sort(arr);
        int minD=Integer.MAX_VALUE;
        for(int i=0;i<arr.length-1;i++){
            if(Math.abs(arr[i]-arr[i+1])<minD){
                minD=Math.abs(arr[i]-arr[i+1]);
            }
        }
       for (int i = 0; i < arr.length; i++) {
            if (hs.contains(arr[i] + minD)) {
                List<Integer> al = new ArrayList<>();
                al.add(arr[i]);
                al.add(arr[i] + minD);
                ans.add(al);
            }
        }
        // FOR THE ABOVE PART YOU CAN ALSO USE THE BINARY SEARCH.

        return ans;
    }
}