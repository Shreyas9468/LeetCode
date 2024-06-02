class Solution {
    public int myAtoi(String s) {
        s = s.trim(); // Remove leading and trailing whitespaces
        if (s.isEmpty()) {
            return 0;
        }

        int i = 0;
        int sign = 1; // to handle the sign of the number
        int result = 0;

        // Check for optional sign
        if (s.charAt(i) == '+' || s.charAt(i) == '-') {
            if (s.charAt(i) == '-') {
                sign = -1;
            }
            i++;
        }

        // Process numerical digits and form the number
        while (i < s.length()) {
            char ch = s.charAt(i);
            if (ch < '0' || ch > '9') {
                break; // break if the current character is not a digit
            }

            // Check for overflow and underflow
            if (result > (Integer.MAX_VALUE - (ch - '0')) / 10) {
                return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }

            result = result * 10 + (ch - '0');
            i++;
        }

        return result * sign;
    }
}
