class Solution {
public:

    int solve(int index, int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        // No days left
        if(index >= prices.size())
            return 0;

        // Already calculated
        if(dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;

        // Buy state
        if(buy)
        {
            int buyStock =
                -prices[index] +
                solve(index+1,0,prices,dp);

            int skip =
                solve(index+1,1,prices,dp);

            profit = max(buyStock,skip);
        }
        // Sell state
        else
        {
            int sellStock =
                prices[index] +
                solve(index+2,1,prices,dp);   // Cooldown

            int skip =
                solve(index+1,0,prices,dp);

            profit = max(sellStock,skip);
        }

        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2,-1));

        return solve(0,1,prices,dp);
    }
};