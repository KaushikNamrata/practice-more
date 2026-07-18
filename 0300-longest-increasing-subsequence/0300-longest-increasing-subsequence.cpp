class Solution {
public:
    int n;
    int dp[2501][2502];

    // i    -> current index
    // prev -> index of previously chosen element
    //         prev = -1 means no element has been chosen yet
    int solve(int i, int prev, vector<int>& nums) {

        // Base case: reached the end of the array
        if (i == n)
            return 0;

        // We store prev+1 because prev can be -1
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        // Option 1: Skip the current element
        int skip = solve(i + 1, prev, nums);

        // Option 2: Take the current element (only if it is increasing)
        int take = 0;

        if (prev == -1 || nums[i] > nums[prev]) {
            // Current index becomes the new previous index
            take = 1 + solve(i + 1, i, nums);
        }

        // Store and return the best answer
        return dp[i][prev + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {

        n = nums.size();

        // Initialize DP with -1 (not computed)
        memset(dp, -1, sizeof(dp));

        // Start from index 0 with no previous element chosen
        return solve(0, -1, nums);
    }
};