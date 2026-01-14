class Solution {
public:
// Helper function: check if we can ship within 'days' using given capacity
    bool canShip(vector<int>& weights, int days, int capacity) {
        int dayCount = 1;       // we start with day 1
        int currentLoad = 0;   // weight loaded on current day

        for (int i = 0; i < weights.size(); i++) {
            // If adding this package exceeds capacity, start a new day
            if (currentLoad + weights[i] > capacity) {
                dayCount++;
                currentLoad = weights[i]; // load this package on new day
            } else {
                currentLoad += weights[i];
            }
        }

        // Check if required days are within limit
        return dayCount <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = 0;
        for(int i = 0 ; i < weights.size();i++){
            high+=weights[i];
        }
        int ans =high;
        // Binary Search on capacity
        while (low <= high) {
            int mid = low + (high - low) / 2; // possible capacity

            if (canShip(weights, days, mid)) {
                // If we can ship with this capacity, try smaller one
                ans = mid;
                high = mid - 1;
            } else {
                // If not possible, we need larger capacity
                low = mid + 1;
            }
        }

        return ans;


    }
};