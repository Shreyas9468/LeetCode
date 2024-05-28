/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public void solve(TreeNode root,HashMap<TreeNode , TreeNode> mp){
         if(root == null) return;

        if(root.left != null) mp.put(root.left , root);

        if(root.right !=null) mp.put(root.right , root);

         solve(root.left,mp);
         solve(root.right,mp);
     }
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        List<Integer> result = new ArrayList<Integer>();
        HashMap<TreeNode , TreeNode> mp = new HashMap< >();
        solve(root , mp);
        HashSet<TreeNode> ks = new HashSet<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(target);
        while(!q.isEmpty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                TreeNode child = q.poll();
                ks.add(child);
                if(k==0) {
                    result.add(child.val);
                }
                if(child.left != null && !ks.contains(child.left)) {
                    q.add(child.left);
                }
                if(child.right != null && !ks.contains(child.right)) {
                    q.add(child.right);
                }
                if(mp.containsKey(child) && !ks.contains(mp.get(child))) {
                    q.add(mp.get(child));
                }
            }
            k--;
            if(k<0) {
                break;
            }
        }
        return result;
    }
}