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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        Queue<TreeNode> q = new LinkedList<>();
        if(root != null){
            q.add(root);
        }
        while(!q.isEmpty()){
            int size  = q.size();
            int last = 0;
            for(int i = 0; i < size; i++){
                TreeNode temp = q.poll();
                last  = temp.val;
                if(temp.left != null){
                    q.add(temp.left);
                }
                if(temp.right != null){
                    q.add(temp.right);
                }
                
            }
            result.add(last);
        }
        return result;


    }
}