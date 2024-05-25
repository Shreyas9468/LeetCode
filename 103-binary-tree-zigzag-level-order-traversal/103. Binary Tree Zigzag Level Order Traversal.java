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
     public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        int level = 0;
        List<List<Integer>> ans = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        if(root != null){
            q.add(root);
        }
        while(!q.isEmpty()){
            int size = q.size();
            List<Integer> zigzag = new ArrayList<>();
            for(int i = 0; i < size; i++){
                TreeNode z = q.poll();
                if(z.left != null){
                    q.add(z.left);

                }
                if(z.right != null){
                    q.add(z.right);
                }
                zigzag.add(z.val);
            }
            if((level &1) !=0 ){
                Collections.reverse(zigzag);
            }
            level++;
            ans.add(zigzag);
        }
        return ans;


    }
}