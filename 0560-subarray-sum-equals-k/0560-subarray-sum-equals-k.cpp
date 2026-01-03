class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;   // base case

    int currSum = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {

        currSum = currSum + nums[i];   // current prefix sum

        if (mp.find(currSum - k) != mp.end()) {
            count = count + mp[currSum - k];
        }

        mp[currSum] = mp[currSum] + 1;
    }

    return count;
    }
};