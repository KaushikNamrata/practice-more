class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

    int cand1 = 0, cand2 = 0;
    int count1 = 0, count2 = 0;

    // Phase 1: find candidates
    for (int i = 0; i < n; i++) {
        if (nums[i] == cand1) {
            count1++;
        } 
        else if (nums[i] == cand2) {
            count2++;
        } 
        else if (count1 == 0) {
            cand1 = nums[i];
            count1 = 1;
        } 
        else if (count2 == 0) {
            cand2 = nums[i];
            count2 = 1;
        } 
        else {
            count1--;
            count2--;
        }
    }

    // Phase 2: verify
    count1 = 0;
    count2 = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == cand1) count1++;
        else if (nums[i] == cand2) count2++;
    }

    vector<int> ans;
    if (count1 > n / 3) ans.push_back(cand1);
    if (count2 > n / 3) ans.push_back(cand2);

    return ans;
    }
};