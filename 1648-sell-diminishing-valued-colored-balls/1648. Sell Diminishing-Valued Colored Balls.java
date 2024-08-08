class Solution {

    private static final int MOD = (int) 1e9 + 7;

    public int maxProfit(int[] inventory, int orders) {
        int n = inventory.length;
        int max = 0;

        for (int x : inventory) {
            max = Math.max(max, x);
        }

        int l = 0, r = max;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (isValid(inventory, orders, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        long res = 0;

        for (int x : inventory) {
            if (x > l) {
                res += (long) (x + l + 1) * (x - l) / 2;
                res %= MOD;
                orders -= x - l;
            }
        }

        res += (long) l * orders;

        return (int) (res % MOD);
    }

    private boolean isValid(int[] inventory, int orders, int mid) {
        long sum = 0;

        for (int x : inventory) {
            sum += Math.max(x - mid, 0);
        }

        return sum <= orders;
    }
}