class Solution {

    List<String> paths = new ArrayList<String>();
    public void solve(TreeNode root , String st){
        if(root == null){
            return;
        }
        st += root.val;
        if(root.left == null && root.right == null){

            paths.add(st);
            return;
        }

        st+= "->";
        solve(root.left, st);
        solve(root.right, st);


    }

    public List<String> binaryTreePaths(TreeNode root) {
        if (root == null) {
            return paths;
        }
        solve(root, "");
        return paths;

    }
}