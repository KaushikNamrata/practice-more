class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long ans = 0;
        long long sum = 0;

        unordered_map<int, int> freq;

        int duplicateCount = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Expand window
            sum += nums[right];

            freq[nums[right]]++;

            if (freq[nums[right]] == 2)
                duplicateCount++;

            // Shrink window if size > k
            while (right - left + 1 > k) {

                if (freq[nums[left]] == 2)
                    duplicateCount--;

                freq[nums[left]]--;

                sum -= nums[left];

                left++;
            }

            // Process window of size k
            if (right - left + 1 == k) {

                if (duplicateCount == 0)
                    ans = max(ans, sum);
            }
        }

        return ans;
    }
};