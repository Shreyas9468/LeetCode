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
    public void solve(TreeNode root , List<Integer> lis){
         if(root == null) return;
         
         solve(root.left , lis);
         lis.add(root.val);
         solve(root.right , lis);
     }
    
    public boolean isValidBST(TreeNode root) {
        List<Integer> lis = new ArrayList<Integer>();
        solve(root , lis);
        for(int i = 0; i < lis.size()-1; i++){
            if(lis.get(i) >= lis.get(i+1)){
                return false;
            }
        }
        return true;
        
    }
}