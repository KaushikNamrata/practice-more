class Solution {
public:
    int n;

    // dp[i] = Maximum sum we can obtain starting from index i
    int dp[501];

    // Recursive function to calculate answer from index i
    int solve(int i, vector<int>& arr, int k) {

        // Base Case:
        // If we have crossed the array, no elements are left.
        if (i >= n) {
            return 0;
        }

        // If already computed, return stored answer.
        if (dp[i] != -1) {
            return dp[i];
        }

        // Stores the maximum answer possible from index i.
        int result = 0;

        // Maximum element in the current partition.
        int curr_max = -1;

        // Try every partition starting from i
        // Partition size can be at most k.
        for (int j = i; j < n && (j - i + 1) <= k; j++) {

            // Update maximum element of current partition.
            curr_max = max(curr_max, arr[j]);

            /*
                Current partition = arr[i...j]

                Length = (j-i+1)

                Every element in this partition becomes curr_max.

                Contribution of current partition:
                length * curr_max

                Remaining answer:
                solve(j+1)

                Total answer =
                current partition contribution
                + remaining partitions
            */
            result =
                max(result, ((j - i + 1) * curr_max) + solve(j + 1, arr, k));
        }

        // Store and return answer.
        return dp[i] = result;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        // Total number of elements.
        n = arr.size();

        // Initialize DP with -1 (not calculated).
        memset(dp, -1, sizeof(dp));

        // Start recursion from index 0.
        return solve(0, arr, k);
    }
};