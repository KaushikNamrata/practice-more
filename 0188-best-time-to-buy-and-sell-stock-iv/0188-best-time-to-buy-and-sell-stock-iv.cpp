class Solution {
public:
    int n;
    int dp[1001][2][101];

    int solve(int i, int buy, int cap, vector<int>& prices) {

        if (i == n || cap == 0)
            return 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        int profit = 0;

        if (buy) {

            int buy_karlo = -prices[i] + solve(i + 1, 0, cap, prices);
            int skip_karlo = solve(i + 1, 1, cap, prices);

            profit = max(buy_karlo, skip_karlo);

        } else {

            int sell_kardo = prices[i] + solve(i + 1, 1, cap - 1, prices);
            int sell_mt_karo = solve(i + 1, 0, cap, prices);

            profit = max(sell_kardo, sell_mt_karo);
        }

        return dp[i][buy][cap] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {

        n = prices.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 1, k, prices);
    }
};