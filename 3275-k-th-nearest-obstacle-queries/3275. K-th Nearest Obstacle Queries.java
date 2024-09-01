import java.util.*;

import java.util.PriorityQueue;

class Solution {
    public int[] resultsArray(int[][] queries, int k) {
        int [] result = new int[queries.length];
        PriorityQueue<Integer> queue = new PriorityQueue<Integer>(Collections.reverseOrder());
        for (int i = 0; i < queries.length;i++){
            int dis = Math.abs( queries[i][0]) + Math.abs( queries[i][1]);
            queue.add(dis);
            if(queue.size()>k){
                queue.poll();
            }
            result[i] = (queue.size()==k) ? queue.peek():-1;
        }
        return result;
    }
}