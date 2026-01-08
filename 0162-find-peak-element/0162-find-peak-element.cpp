class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        // Binary search
        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid element is smaller than next element,
            // then the peak lies on the right side
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            }
            // Otherwise, the peak lies on the left side (or at mid)
            else {
                high = mid;
            }
        }

        // When low == high, we have found a peak element
        return low;
    }
};
