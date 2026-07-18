class Solution {
public:

    // Function to calculate GCD using Euclid's Algorithm
    int gcd(int a, int b) {

        // Repeat until remainder becomes 0
        while (b != 0) {
            int rem = a % b; // Find remainder
            a = b;           // Move b to a
            b = rem;         // Move remainder to b
        }

        // 'a' now contains the GCD
        return a;
    }

    int findGCD(vector<int>& nums) {

        // Assume first element is both minimum and maximum
        int mini = nums[0];
        int maxi = nums[0];

        // Traverse the array to find smallest and largest element
        for (int i = 1; i < nums.size(); i++) {

            // Update minimum
            if (nums[i] < mini)
                mini = nums[i];

            // Update maximum
            if (nums[i] > maxi)
                maxi = nums[i];
        }

        // Return GCD of minimum and maximum numbers
        return gcd(mini, maxi);
    }
};