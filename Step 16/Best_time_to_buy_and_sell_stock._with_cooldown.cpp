#include <bits/stdc++.h> 
int solve(vector<int> &prices, int n, vector<vector<int>>& dp, int i, int hold)
{
    if(i >= n)
        return 0;
    if(dp[hold][i] != -1)
        return dp[hold][i];
    
    int profit = 0;
    if(hold == 1)
    {
        int sprofit = solve(prices, n, dp, i+2, 0) + prices[i];
        int nosell = solve(prices, n, dp, i+1, 1);
        profit = max(sprofit, nosell);
    }
    else
    {
        int buy = solve(prices, n, dp, i+1, 1) - prices[i];
        int nobuy = solve(prices, n, dp, i+1, 0);
        profit = max(buy, nobuy);
    }
    dp[hold][i] = profit;
    return profit;
}
int stockProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(2, vector<int> (n+1, -1));
    int ans = solve(prices, n, dp, 0, 0);
    return ans;
}