import java.util.Stack;

class Solution {
    public  boolean isValid(String s) {
        Stack<Character> st = new Stack<Character>();

        for(int i = 0; i < s.length(); i++){
            Character c = s.charAt(i);
            if(st.isEmpty()){
                if(c == ')' || c == '}' || c == ']'){
                    return false;
                }
            }
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else{
                if(c == ')'){
                    if(st.peek() != '('){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                }
                if(c == '}'){
                    if(st.peek() != '{'){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                }
                if(c == ']'){
                    if(st.peek() != '['){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                }

            }
        }
        return st.isEmpty();
    }

   


}
//Example 1:
//
//Input: s = "()"
//Output: true
//Example 2:
//
//Input: s = "()[]{}"
//Output: true
//Example 3:
//
//Input: s = "(]"
//Output: false