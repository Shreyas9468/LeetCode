class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> levelOrder = new ArrayList<List<Integer>>();
        if(root == null) {
            return levelOrder;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> level = new ArrayList<>();
            for(int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                if(node.left !=null) {
                     queue.add(node.left);
                }
                if(node.right !=null) {
                    queue.add(node.right);
                }
                level.add(node.val);
            }
            levelOrder.add(level);
        }
        return levelOrder;

    }
}