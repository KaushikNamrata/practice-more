class Solution {
public:
    long long mergeAndCount(vector<int>& nums, int low, int mid, int high) {
        long long count = 0;
        
        // 🔹 COUNT reverse pairs
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        
        // 🔹 MERGE step (normal merge sort)
        vector<int> temp;
        int left = low, right = mid + 1;
        
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        
        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);
        
        // copy back
        int k = 0;
        for (int i = low; i <= high; i++) {
            nums[i] = temp[k++];
        }
        
        return count;
    }
    
    long long mergeSort(vector<int>& nums, int low, int high) {
        long long count = 0;
        if (low < high) {
            int mid = (low + high) / 2;
            count += mergeSort(nums, low, mid);
            count += mergeSort(nums, mid + 1, high);
            count += mergeAndCount(nums, low, mid, high);
        }
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};