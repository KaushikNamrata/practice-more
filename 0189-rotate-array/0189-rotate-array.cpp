class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        //step 1 phle pura array reverse krenge
        reverse(nums.begin(),nums.end());

        //step 2 fir hum first k elements reverse krenge
        reverse(nums.begin(),nums.begin()+k);


        //step-3 fir hum remaining n-k elements reverse krenge
        reverse(nums.begin()+k,nums.end());

    }
};