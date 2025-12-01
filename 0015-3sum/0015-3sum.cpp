class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> result;
        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix one element nums[i]
        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate i (same value used before)
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                // CASE 1: Triplet found
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate left values
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // Skip duplicate right values
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // Move both pointers after recording
                    left++;
                    right--;
                }

                // CASE 2: Sum too small → increase left
                else if (sum < 0) {
                    left++;
                }

                // CASE 3: Sum too big → decrease right
                else {
                    right--;
                }
            }
        }

        return result;  
    }
};