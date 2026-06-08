class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>less,equal,greater;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                less.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                equal.push_back(nums[i]);
            }
            else{
                greater.push_back(nums[i]);
            }
        }
        vector<int>ans;
        for(int x: less)ans.push_back(x);
        for(int x: equal)ans.push_back(x);
        for(int x: greater)ans.push_back(x);

        return ans;

    }
};