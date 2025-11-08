class Solution {
public:
     int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Precompute powers of 2 modulo MOD
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2LL) % MOD;
        }

        long long result = 0;
        int l = 0, r = n - 1;

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                // all elements between l and r can be chosen or not (r - l choices)
                result = (result + power[r - l]) % MOD;
                l++;
            } else {
                r--;
            }
        }

        return (int)result;
    }
};