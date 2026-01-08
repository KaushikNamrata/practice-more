class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If target is found
            if (nums[mid] == target)
                return true;

            // If we cannot determine the sorted half due to duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }

            // If left half is sorted
            else if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            // Otherwise, right half is sorted
            else {
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};   // ✅ This closing brace was missing or misplaced
