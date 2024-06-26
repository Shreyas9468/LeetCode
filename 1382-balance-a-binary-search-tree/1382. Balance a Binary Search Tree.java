import java.util.*;

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
     void solve(List<Integer>ilis , TreeNode root){
         if(root == null){
             return;
         }
         solve(ilis , root.left);
         ilis.add(root.val);
         solve(ilis , root.right);
     }

     TreeNode solve1(List<Integer>ilis , int s , int e){
         if(s>e){
             return null;
         }
         int mid = s + (e-s)/2;
         TreeNode curr = new TreeNode(ilis.get(mid));
         curr.left = solve1(ilis , s , mid-1);
         curr.right = solve1(ilis , mid+1 ,e );
         return curr;
     }


    public TreeNode balanceBST(TreeNode root) {
        List<Integer>ilis = new ArrayList<Integer>();
        solve(ilis,root);
        int n = ilis.size();
        return solve1(ilis , 0 ,n-1 );
    }
}