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
    private TreeNode root;
     public void populatesorted(int [] nums){
        populatesortedinsert(nums , 0 , (int)nums.length);
    }
    private void populatesortedinsert(int [] nums, int start , int end){
        if(start >= end){
            return ;
        }
        int mid = start + (end - start) / 2;
        this.insert(nums[mid]);
        populatesortedinsert(nums, start , mid);
        populatesortedinsert(nums, mid +1,end);
    }
    public void insert(int value) {
        root = insert(root, value);
    }

    private TreeNode insert(TreeNode node, int value) {
        if (node == null) {
            return new TreeNode(value);
        }

        if (value < node.val) {
            node.left = insert(node.left, value);
        } else if (value > node.val) {
            node.right = insert(node.right, value);
        }

        //node.height = Math.max(height(node.left), height(node.right)) + 1;
        return node;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        populatesorted(nums);
        return root;
    }
}