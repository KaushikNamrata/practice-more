class Solution {
public:
    int n;
    int dp[201][201];
    bool vis[201][201];

    int solve(int i, int j, vector<vector<int>>& triangle) {

        // Base case
        if (i == n - 1)
            return triangle[i][j];

        // Already computed
        if (vis[i][j])
            return dp[i][j];

        int down = solve(i + 1, j, triangle);
        int diagonal = solve(i + 1, j + 1, triangle);

        vis[i][j] = true;
        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();

        memset(vis, false, sizeof(vis));

        return solve(0, 0, triangle);
    }
};