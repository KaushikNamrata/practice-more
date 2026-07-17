class Solution {
public:
int n;
int dp [50001][2];

int solve(int i, int fee, int buy, vector<int>&prices){
      if(i==n){
        return 0;
      }
      if(dp[i][buy]!=-1){
        return dp[i][buy];
      }
      int profit =0;
      if(buy){

        int buy_karo = -prices[i]+ solve(i+1,fee,0,prices);
        int buy_mt_karo = solve(i+1,fee,1,prices);

        profit = max(buy_karo,buy_mt_karo);
      }
      else{
        int sell_kardo = prices[i]-fee+solve(i+1,fee,1,prices);
        int skip_kardo= solve(i+1,fee,0,prices);
        profit=max(sell_kardo , skip_kardo);
      }
      return dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices, int fee) {
        n=prices.size();
        memset(dp,-1,sizeof(dp));

        return solve(0,fee,1,prices);
    }
};