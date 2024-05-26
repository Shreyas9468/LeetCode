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
    int sum = 0;
    public void solve1(TreeNode root){
        if(root== null) {
            return;
        }
        
        if(root.left!=null){
            if(root.left.left == null && root.left.right == null) {
            sum += root.left.val;
        }
        }
        solve1(root.left);
        solve1(root.right);

    }
    public int sumOfLeftLeaves(TreeNode root) {
        solve1(root);
        return sum;

    }
}