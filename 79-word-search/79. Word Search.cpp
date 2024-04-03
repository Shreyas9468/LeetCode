class Solution {
public:

    bool backtrack(vector<vector<char>>& board, string word, int row, int col, int index) {
        if (index == word.length()) {
            return true; // Entire word is found
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false; // Out of bounds or characters don't match
        }
        char original = board[row][col];
        board[row][col] = '#'; // Mark the cell as visited
        // Explore adjacent cells
        bool found = backtrack(board, word, row + 1, col, index + 1)
                    || backtrack(board, word, row - 1, col, index + 1)
                    || backtrack(board, word, row, col + 1, index + 1)
                    || backtrack(board, word, row, col - 1, index + 1);
        board[row][col] = original; // Restore the cell's original value
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        // Implement your logic for word search here
        // You need to fill in the logic for the exist function
        // This function should return true if the word exists in the board
        // Otherwise, it should return false
        // You can use backtracking or any other suitable algorithm to solve this problem
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == word[0]) {
                    if (backtrack(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};