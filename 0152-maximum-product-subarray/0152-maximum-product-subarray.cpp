class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {

            // If current element is negative, swap
            if (nums[i] < 0) {
                int temp = maxProd;
                maxProd = minProd;
                minProd = temp;
            }

            // Update max and min product
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            // Update answer
            if (maxProd > ans) {
                ans = maxProd;
            }
        }

        return ans;
    }
};
