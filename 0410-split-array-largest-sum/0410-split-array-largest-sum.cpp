class Solution {
public:
bool ispossible(vector<int>&nums,int k,int mid){
    int studentcount=1,pagesum=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid) return false;
        if(pagesum+nums[i]<=mid){
            pagesum+=nums[i];
        }
        else{
            studentcount++;
            if(studentcount>k) return false;
            pagesum=nums[i];
        }
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        if(k> nums.size()) return -1;
        int s=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int e=sum; 
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(ispossible(nums,k,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};