import java.util.Stack;

class Solution {
    public String removeOuterParentheses(String s) {
        String ans = "";
        //(()())(())(()(()))
        Stack<Character> st = new Stack<Character>();
        for(int i = 0;i<s.length();i++) {
            if(s.charAt(i) == '(' ) {
                if(!st.isEmpty()){
                    ans+="(";
                }
                st.push(s.charAt(i));
                
            }
            else{
                st.pop();
                if(!st.isEmpty()) {
                  ans += ")";
                }
            }
        }
        return ans;
    }

}