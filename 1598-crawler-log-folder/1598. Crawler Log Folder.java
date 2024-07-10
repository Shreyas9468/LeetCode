import java.util.Objects;
import java.util.Stack;

class Solution {
    public int minOperations(String[] logs) {
        Stack<String> stack = new Stack<String>();
        stack.push("Main");
        for(int i = 0; i < logs.length; i++){
            String log = logs[i];
            if(log.equals("../")){
                if(stack.peek().equals("Main")){
                    continue;
                }
                else{
                    stack.pop();
                }
            }
            else if(log.equals("./")){
                continue;
            }
            else{
                stack.push(log);
            }
        }

        int cnt =0;
        while(!Objects.equals(stack.peek(), "Main")){
            cnt++;
            stack.pop();
        }
        return cnt;

    }
}