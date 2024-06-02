class Solution {
    public int maxDepth(String s) {
        int curr = 0;
        int depth = 0;
        for(int i = 0;i<s.length();i++){
            Character ch = s.charAt(i);
            if(ch =='('){
                curr++;
            }
            else if(ch == ')'){
                depth = Math.max(curr, depth);
                curr--;
            }
        }
        return depth;
    }
}