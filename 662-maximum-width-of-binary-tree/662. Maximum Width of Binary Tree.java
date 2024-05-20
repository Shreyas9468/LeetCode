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
  class TreeNode {
  int data;
  TreeNode  left,  right;
  TreeNode(int data){
      this.data=data;
      left=null;
      right=null;
  }
}

  class Pair {
    TreeNode node; 
    int num; 
    Pair(TreeNode _node, int _num) {
        num = _num;
        node = _node; 
    }
}

class Solution {


    public int widthOfBinaryTree(TreeNode root) {
        if(root==null) return 0;
    Deque<Pair> q1 = new LinkedList<>();
       int max=0;
        q1.addLast(new Pair(root, 0));

        while(!q1.isEmpty()){
        int size=q1.size();

         Pair a=q1.getFirst();
         Pair b=q1.getLast();
           
           int sum=b.num-a.num+1;
            max=Math.max(sum,max);   
           

            for(int i=0;i<size;i++){
                
               Pair root1=q1.removeFirst();
              
                 if(root1.node.left!=null)q1.addLast(new Pair(root1.node.left, 2*root1.num+1));

                 if(root1.node.right!=null) q1.addLast(new Pair(root1.node.right, 2*root1.num+2));
                 
                     
            }
        }
        return max;
    }
}