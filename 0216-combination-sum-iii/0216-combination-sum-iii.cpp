class Solution {
public:

    void solve(int start,int k, int n,vector<int>&curr,vector<vector<int>>&result){
        //basecase
        if(k==0 && n==0){
            result.push_back(curr);
            return;
        }
        if(k==0 && n<0){
            return;
        }
        for(int i = start; i<=9 ;i++){
            curr.push_back(i);
            solve(i+1,k-1,n-i,curr,result);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> curr;
        solve(1, k, n, curr, result);
        return result; 
    }
};