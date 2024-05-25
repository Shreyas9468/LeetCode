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
    public int height(TreeNode node) {
        if (node == null) return -1;
        int lh = height(node.left);
        int rh = height(node.right);
        return Math.max(lh, rh) + 1;
    }
    public int maxDepth(TreeNode root) {

        if(root ==null) return 0;
        int rh = height(root.right)+1;
        int lh = height(root.left)+1;
        return Math.max(lh, rh ) +1;
        
    }
}