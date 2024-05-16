class Solution {
    public boolean evaluateTree(TreeNode root) {
        // Base condition, if it's a leaf node
        if(root.left == null && root.right == null){
            if(root.val == 0) return false;
            return true;
        }
        // If it's not a leaf node, then go to left subtree
        boolean left = evaluateTree(root.left);
        // then go to right subtree
        boolean right = evaluateTree(root.right);
        // OR operation
        if(root.val == 2) return left || right;
        return left && right; // AND operation
    }
}