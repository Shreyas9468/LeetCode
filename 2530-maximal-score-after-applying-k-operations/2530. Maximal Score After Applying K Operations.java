import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    public long maxKelements(int[] nums, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());

        for (int num : nums) {
            maxHeap.offer(num);

        }
        long ans = 0;
        for(int i =0;i<k;i++){
            int top = maxHeap.peek();
            ans += top;
            maxHeap.poll();
            maxHeap.offer((int) Math.ceil((double) top /3)); 
        }

        return ans;
    }
}