class Solution {
public:
    int dp[305][305];
    int solve(int i, int j, vector<int>& nums) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        for (int k = i; k <= j; k++) {
            int left = solve(i, k - 1, nums);
            int right = solve(k + 1, j, nums);
            int curr = nums[i - 1] * nums[k] * nums[j + 1];

            ans = max(ans, left + curr + right);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(dp, -1, sizeof(dp));

        return solve(1, n, nums);
    }
};