public class Solution {
    // Helper method to calculate GCD
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        // Initialize result list
        ListNode result = new ListNode(head.val); // First node value
        ListNode temp = result;

        ListNode left = head;
        ListNode right = head.next;

        // Traverse the list
        while (right != null) {
            // Calculate GCD of left and right values
            int a = left.val;
            int b = right.val;
            int c = gcd(a, b);

            // Insert the GCD node between the current nodes
            temp.next = new ListNode(c);
            temp = temp.next;

            // Insert the right node
            temp.next = new ListNode(right.val);
            temp = temp.next;

            // Move left and right pointers to the next pair
            left = right;
            right = right.next;
        }

        return result;
    }
}
