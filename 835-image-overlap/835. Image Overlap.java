class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
        int n = img1.length;
        int[][] m = new int[2 * n + 1][2 * n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) {
                    for (int p = 0; p < n; p++) {
                        for (int q = 0; q < n; q++) {
                            if (img2[p][q] == 1) {
                                m[i - p + n][j - q + n]++;
                            }
                        }
                    }
                }
            }
        }
        int max = 0;
        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m.length; j++) {
                max = Math.max(max, m[i][j]);
            }
        }
        return max;
    }
}