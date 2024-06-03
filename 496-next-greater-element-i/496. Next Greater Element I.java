import java.util.*;

class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> nextGreaterMap = new HashMap<>();
        Stack<Integer> stack = new Stack<>();
        
        // Traverse nums2 in reverse order to find next greater elements
        for (int i = nums2.length - 1; i >= 0; i--) {
            // Maintain the stack such that it always contains elements in descending order
            while (!stack.isEmpty() && stack.peek() <= nums2[i]) {
                stack.pop();
            }
            
            // If the stack is empty, it means there is no greater element to the right
            if (stack.isEmpty()) {
                nextGreaterMap.put(nums2[i], -1);
            } else {
                nextGreaterMap.put(nums2[i], stack.peek());
            }
            
            // Push the current element onto the stack
            stack.push(nums2[i]);
        }
        
        // Create the result array using the nextGreaterMap
        int[] result = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++) {
            result[i] = nextGreaterMap.getOrDefault(nums1[i], -1);
        }
        
        return result;
    }

   
}
