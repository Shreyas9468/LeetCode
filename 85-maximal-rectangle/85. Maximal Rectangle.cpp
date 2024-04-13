#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = (i == 0) ? 1 : dp[i - 1][j] + 1;
                }

                int minHeight = dp[i][j];
                for (int k = j; k >= 0; k--) {
                    minHeight = min(minHeight, dp[i][k]);
                    if (minHeight == 0) {
                        break; // If height becomes 0, the rectangle ends
                    }
                    int width = j - k + 1;
                    maxArea = max(maxArea, width * minHeight);
                }
            }
        }

        return maxArea;
    }
};
