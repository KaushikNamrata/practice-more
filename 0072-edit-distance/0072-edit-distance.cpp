class Solution {
public:
    int m, n;
    int dp[501][501];

    int solve(string &s1, string &s2, int i, int j) {

        // Base Case 1:
        // If s1 is exhausted, insert the remaining characters of s2
        if (i == m) {
            return n - j;
        }

        // Base Case 2:
        // If s2 is exhausted, delete the remaining characters of s1
        if (j == n) {
            return m - i;
        }

        // If already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters match, no operation needed
        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);
        }

        // Case 1: Insert
        // Insert s2[j] into s1, so move only j
        int insert = 1 + solve(s1, s2, i, j + 1);

        // Case 2: Delete
        // Delete s1[i], so move only i
        int del = 1 + solve(s1, s2, i + 1, j);

        // Case 3: Replace
        // Replace s1[i] with s2[j], move both
        int replace = 1 + solve(s1, s2, i + 1, j + 1);

        // Store and return minimum of all three operations
        return dp[i][j] = min({insert, del, replace});
    }

    int minDistance(string s1, string s2) {

        m = s1.length();
        n = s2.length();

        // Initialize DP array with -1
        memset(dp, -1, sizeof(dp));

        return solve(s1, s2, 0, 0);
    }
};