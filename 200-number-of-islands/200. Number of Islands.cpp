class Solution {
public:
    // Recursive function to mark all connected land cells as visited
    void solve(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Mark current cell as visited
        vis[r][c] = 1;
        
        // Define movements in up, down, left, and right directions
        int dp1[4] = {1, -1, 0, 0};
        int dp2[4] = {0, 0, -1, 1};
        
        // Check all four adjacent cells
        for (int i = 0; i < 4; i++) {
            int nr = dp1[i] + r; // new row
            int nc = dp2[i] + c; // new column
            
            // Check if the adjacent cell is within the grid boundaries,
            // unvisited, and contains land ('1')
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == '1') {
                // Recursively call solve function for the adjacent land cell
                solve(nr, nc, grid, vis);
            }
        }
    }
    
    // Main function to count the number of islands
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        // Matrix to keep track of visited cells
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // Iterate through each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If current cell is land ('1') and not visited
                if (grid[i][j] == '1' && !vis[i][j]) {
                    // Call solve function to mark all connected land cells as visited
                    solve(i, j, grid, vis);
                    // Increment island count
                    ans++;
                }
            }
        }
        
        // Return the total number of islands
        return ans;
    }
};