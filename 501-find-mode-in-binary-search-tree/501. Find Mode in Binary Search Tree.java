/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    HashMap<Integer , Integer> hashMap = new HashMap<>();

    public void solve2(TreeNode root) {
        if(root ==null) return;
        hashMap.put(root.val, hashMap.getOrDefault(root.val,0)+1);
        solve2(root.left);
        solve2(root.right);
    }
    public int[] findMode(TreeNode root) {
       // HashMap<Integer , Integer> hashMap = new HashMap<>();
        solve2(root);
        int maxFrequency = 0;
        for (int frequency : hashMap.values()) {
            if (frequency > maxFrequency) {
                maxFrequency = frequency;
            }
        }
        List<Integer> modes = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : hashMap.entrySet()) {
            if (entry.getValue() == maxFrequency) {
                modes.add(entry.getKey());
            }
        }

        // Convert the list to an array
        int[] result = new int[modes.size()];
        for (int i = 0; i < modes.size(); i++) {
            result[i] = modes.get(i);
        }
        return result;
    }
}