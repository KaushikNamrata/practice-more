class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int odd_count=0;
        int ans=0;

        for(int i = 0 ;i<nums.size();i++){
            if(nums[i]%2==1)
                odd_count++;
                ans+=mp[odd_count-k];

                mp[odd_count]++;
            

        }
        return ans;
    }
};