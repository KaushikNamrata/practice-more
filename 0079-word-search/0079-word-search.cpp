class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtrack(board, word, i, j, 0))   // start DFS if first char matches
                    return true;
            }
        }
        return false;
    }
    private:
    bool backtrack(vector<vector<char>>& board, string& word, int row, int col, int index) {
        // ✅ base case — all characters matched
        if (index == word.size())
            return true;

        // ❌ invalid move or mismatch
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size() ||
            board[row][col] != word[index])
            return false;

        // temporarily mark as visited
        char temp = board[row][col];
        board[row][col] = '*';

        // explore in all 4 directions
        bool found = backtrack(board, word, row + 1, col, index + 1) ||  // down
                     backtrack(board, word, row - 1, col, index + 1) ||  // up
                     backtrack(board, word, row, col + 1, index + 1) ||  // right
                     backtrack(board, word, row, col - 1, index + 1);    // left

        // restore the cell (backtrack step)
        board[row][col] = temp;

        return found;
    }


};