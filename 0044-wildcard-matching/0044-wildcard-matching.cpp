class Solution {
public:
int m;
int n;
int dp[2001][2001];

int solve(string& s, string& p,int i, int j){
    //base case
    if(i<0 && j<0)
    return true;      //pattern match hogya ha

    if(i>=0 && j<0)
    return false;     //string s bchi ha p complete hogyi

    if(i<0 && j>=0){
        for(int k=0;k<=j;k++){
            if(p[k] !='*'){
                return false;
            }
        }
        return true;
    }
   if(dp[i][j] != -1)
   return dp[i][j];
   //pattern match
   if(s[i]==p[j] || p[j]=='?')
   return dp[i][j]=solve(s,p,i-1,j-1);

   else if(p[j]=='*')
   return dp[i][j]=solve(s,p,i-1,j) || solve(s,p,i,j-1);

   else
   return dp[i][j]=false;

}
    bool isMatch(string s, string p) {
        m=s.length();
        n=p.length();
        memset(dp,-1,sizeof(dp));

        return solve(s,p,m,n);
    }
};