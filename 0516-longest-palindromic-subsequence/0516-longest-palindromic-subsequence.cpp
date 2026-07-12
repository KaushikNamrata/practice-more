class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(string& s1, string& s2, int i, int j) {
        // base case
        if (i == n || j == n) {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j]) { // pattern match
            return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        }
        int include_i = solve(s1, s2, i + 1, j);
        int include_j = solve(s1, s2, i, j + 1);

        return dp[i][j] = max(include_i, include_j);
    }

    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(s.begin(), s.end());
        n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(s, rev, 0, 0);
    }
};