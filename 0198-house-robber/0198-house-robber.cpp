class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //t[i]=maximum money stolen till house i
        if(n==1)
        return nums[0];
        vector<int>t(n+1,0);
        // no house
        t[0]=0;
        //1 house
        t[1]=nums[0];
        
        for(int i = 2; i<=nums.size();i++){
            int steal=nums[i-1]+t[i-2];
            int skip=t[i-1];
            t[i]=max(steal,skip);
        }
        return t[n];
    }
};