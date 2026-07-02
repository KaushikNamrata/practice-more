class Solution {
public:

    // Function to check if there exists a subset with given sum
    bool subsetSum(vector<int>& nums, int sum) {

        int n = nums.size();

        // dp[i][j] = Can we make sum 'j' using first 'i' elements?
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // Base Case:
        // Sum 0 can always be formed by taking no elements
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= sum; j++) {

                // Current element can be included
                if (nums[i - 1] <= j) {

                    dp[i][j] = dp[i - 1][j] ||
                               dp[i - 1][j - nums[i - 1]];
                }

                // Current element cannot be included
                else {

                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }

    bool canPartition(vector<int>& nums) {

        int totalSum = 0;

        // Find total sum
        for (int num : nums) {
            totalSum += num;
        }

        // If total sum is odd, equal partition is impossible
        if (totalSum % 2 != 0) {
            return false;
        }

        // Check if subset with sum = totalSum/2 exists
        return subsetSum(nums, totalSum / 2);
    }
};