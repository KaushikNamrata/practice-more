class Solution {
public:
    int m, n;
    int dp[201][201];

    int solve(int i, int j, vector<vector<int>>& grid) {

        // Destination reached
        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        // Out of bounds
        if (i >= m || j >= n)
            return 1e9;   // Large value

        // Already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(i, j + 1, grid);
        int down = solve(i + 1, j, grid);

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, grid);
    }
};