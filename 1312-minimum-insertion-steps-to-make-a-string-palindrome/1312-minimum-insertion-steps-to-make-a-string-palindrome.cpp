class Solution {
public:
    int m, n;
    int dp[501][501];

    int solve(string& s1, string& s2, int i, int j) {

        // Base Case
        if (i >= m || j >= n)
            return 0;

        // Already Calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters Match
        if (s1[i] == s2[j])
            return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);

        // Characters Don't Match
        return dp[i][j] = max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
    }

    int minInsertions(string s) {

        string rev = s;
        reverse(rev.begin(), rev.end());

        m = s.length();
        n = rev.length();

        memset(dp, -1, sizeof(dp));

        int lps = solve(s, rev, 0, 0);

        return m - lps;
    }
};