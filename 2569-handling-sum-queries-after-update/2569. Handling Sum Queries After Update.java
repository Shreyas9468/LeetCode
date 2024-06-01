class Solution {
    public long[] handleQuery(int[] nums1, int[] nums2, int[][] queries) {
        List<Long> list = new ArrayList<>();
        long answer = 0L;
        int n = nums1.length;
        for(int i=0;i<n;i++) if(nums1[i] == 0) nums1[i] = -1;
        SegmentTree sg = new SegmentTree(nums1);
        for(int a: nums2) answer += a;
        for(int[] q: queries){
            if(q[0] == 1) sg.multiplyToRange(q[1],q[2],-1);
            else if(q[0] == 2) answer += q[1]*((sg.getSumInRange(0,n-1)+n)/2);
            else list.add(answer);
        }
        long[] ans = new long[list.size()];
        for(int i=0;i<ans.length;i++) ans[i] = list.get(i);
        return ans;
    }

}
class SegmentTree{
    long[] segmentArray;
    long[] lazy;
    int length;

    public SegmentTree(int[] nums){
        this.length = nums.length;
        int height = (int)Math.ceil(Math.log(length)/Math.log(2));
        int lengthOfSegmentTree = 2*(1<<height)-1;
        this.segmentArray = new long[lengthOfSegmentTree];
        this.lazy = new long[lengthOfSegmentTree];
        Arrays.fill(lazy,1L);
        constructor(0,length-1,0,nums);
    }
    private long constructor(int ss, int se, int si,int[] nums){
        if(ss == se) return segmentArray[si] = nums[ss];
        int mid = (ss+se)/2;
        return segmentArray[si] = constructor(ss,mid,2*si+1,nums)+constructor(mid+1,se,2*si+2,nums);
    }
    public void multiplyToRange(int left, int right, long value){
        mul(0,length-1,0,left,right,value);
    }
    private long mul(int ss, int se, int si, int qs, int qe, long value){
        if(se<qs || qe<ss) return segmentArray[si];
        if(ss != se) propagate(si);
        if(qs<=ss && se<=qe){
            lazy[si] = value;
            return segmentArray[si] = (segmentArray[si]*value);
        }
        int mid = (ss+se)>>1;
        return segmentArray[si] = (mul(ss,mid,2*si+1,qs,qe,value)+mul(mid+1,se,2*si+2,qs,qe,value));
    }

    public long getSumInRange(int left, int right){
        return getSum(0,length-1,0,left,right);
    }

    private long getSum(int ss, int se, int si, int qs, int qe){
        if(se<qs || qe<ss) return 0L;
        if(ss != se) propagate(si);
        if(qs<=ss && se<=qe) return segmentArray[si];
        int mid = (ss+se)>>1;
        return (getSum(ss,mid,2*si+1,qs,qe)+ getSum(mid+1,se,2*si+2,qs,qe));
    }


    private void propagate(int si){
        if(lazy[si]!=1){
            segmentArray[2*si+1] = (segmentArray[2*si+1]*lazy[si]);
            segmentArray[2*si+2] = (segmentArray[2*si+2]*lazy[si]);
            lazy[2*si+1] = (lazy[2*si+1]*lazy[si]);
            lazy[2*si+2] = (lazy[2*si+2]*lazy[si]);
            lazy[si] = 1;
        }
    }
}
