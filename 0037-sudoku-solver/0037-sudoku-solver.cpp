class Solution {
public:

    bool isvalid(vector<vector<char>>& board, int row, int col, char d) {

        // Check row and column
        for (int i = 0; i < 9; i++) {

            if (board[i][col] == d)
                return false;

            if (board[row][i] == d)
                return false;
        }

        // Check 3x3 box
        int start_i = row / 3 * 3;
        int start_j = col / 3 * 3;

        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {

                if (board[start_i + k][start_j + l] == d)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                // Find empty cell
                if (board[i][j] == '.') {

                    // Try digits 1 to 9
                    for (char d = '1'; d <= '9'; d++) {

                        if (isvalid(board, i, j, d)) {

                            // Place digit
                            board[i][j] = d;

                            // Recursively solve
                            if (solve(board) == true) {
                                return true;
                            }

                            // Backtrack
                            board[i][j] = '.';
                        }
                    }

                    // No digit worked
                    return false;
                }
            }
        }

        // No empty cell left
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};