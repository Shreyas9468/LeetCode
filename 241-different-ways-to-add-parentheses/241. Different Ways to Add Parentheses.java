import java.util.*;

class Solution {
    public List<Integer> diffWaysToCompute(String expression) {
        List<Integer> result = new ArrayList<Integer>();
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                List<Integer> left = diffWaysToCompute(expression.substring(0, i));
                List<Integer> right = diffWaysToCompute(expression.substring(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        switch (c) {
                            case '+': result.add(l + r); break;
                            case '-': result.add(l - r); break;
                            case '*': result.add(l * r); break;
                        }
                    }
                }
            }
        }
        if(result.isEmpty()){
            result.add(Integer.parseInt(expression));  // If there's no operator, it's a number.  Convert it to int and add it to the list.  return the list.  If the list is empty, it means all the numbers were added together, so return the number itself.  This is the base case for the recursion.  The recursion will eventually reach this case.  In this case, it's a number.  So, we add it to the list.  The list will contain only one number, which is the number itself.  This is the base case for the recursion.  The recursion will eventually reach this case.  In this case, it's a number.  So, we add it to the list.  The list will contain only one number, which is the number itself.  This is the base case for the recursion.  The recursion will eventually reach this case.  In this case, it's a number.'
        }
        return result;
    }
}