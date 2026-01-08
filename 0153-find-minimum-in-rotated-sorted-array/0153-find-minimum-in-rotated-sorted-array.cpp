class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();        // ✅ size, not size-1
        int low = 0, high = n - 1;

        while (low <= high) {

            // Case 1: Already sorted
            if (nums[low] <= nums[high])
                return nums[low];

            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            // Case 2: Mid is the minimum element
            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                return nums[mid];   // ✅ return value, not index

            // Case 3: Right half is sorted → go left
            else if (nums[mid] <= nums[high])
                high = mid - 1;

            // Case 4: Left half is sorted → go right
            else
                low = mid + 1;
        }
        return -1;
    }
};
