class Solution {
public:
    int n;
    int dp[50001][2];
    int solve(vector<int>& prices, int index, int buy) {
        if (index == n)
            return 0; 

        if(dp[index][buy]!=-1)
        return dp[index][buy];

        int profit = 0;
        if (buy) {
            int buykaro = -prices[index] + solve(prices, index + 1, 0);
            int skipkaro = 0 + solve(prices, index + 1, 1);
            profit = max(buykaro, skipkaro);
        } else {
            int sellkaro = prices[index] + solve(prices, index + 1, 1);
            int skipkaro = 0 + solve(prices, index + 1, 0);
            profit = max(sellkaro, skipkaro);
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp,-1,sizeof(dp));

        return solve(prices, 0, 1);
    }
};