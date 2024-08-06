class Solution {
    HashMap<Integer, Integer> map;
    int row;
    int col;
    Random ran;
    int total;

    public Solution(int m, int n) {
        map = new HashMap<>();
        ran = new Random();
        row = m;
        col = n;
        total = row * col;
    }

    public int[] flip() {
        int r = ran.nextInt(total);
        int x = map.getOrDefault(r, r);
        total--;
        map.put(r, map.getOrDefault(total, total));
        
        return new int[] { x / col, x % col };
    }

    public void reset() {
        map.clear();
        total = row * col;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(m, n);
 * int[] param_1 = obj.flip();
 * obj.reset();
 */