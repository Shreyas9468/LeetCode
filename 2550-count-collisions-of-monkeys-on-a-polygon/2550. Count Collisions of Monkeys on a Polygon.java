class Solution {
    private static int max = 1000000007;
    public int monkeyMove(int n) {
//         given in questions
         
         return (int) ((max + pow(n) - 2) % max);
    }
    private static long pow(int n) {
		if (n == 1)
			return 2;
		if (n % 2 == 0) {
			long half = pow(n / 2);
			return (half * half) % max;
		} else {
			long half = pow(n / 2);
			return ((half * half) % max) * 2 % max;
		}
		
	}
}