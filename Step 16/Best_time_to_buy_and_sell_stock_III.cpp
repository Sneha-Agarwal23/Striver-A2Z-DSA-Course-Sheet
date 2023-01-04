#include <bits/stdc++.h> 
int solve(vector<int>& prices, int n, vector<vector<vector<int>>> &dp, int i, int buy, int hold)
{
    if(i == n or hold == 0)
        return 0;
    if(dp[i][buy][hold] != -1)
        return dp[i][buy][hold];
    
    if(buy == 1)
    {
        int sell = solve(prices, n, dp, i+1, 0, hold) - prices[i];
        int notsell = solve(prices, n, dp, i+1, 1, hold);
        dp[i][buy][hold] = max(sell, notsell);
    }
    else
    {
        int b = solve(prices, n, dp, i+1, 1, hold-1) + prices[i];
        int notbuy = solve(prices, n, dp, i+1, 0, hold);
        dp[i][buy][hold] = max(b, notbuy);
    }
    return dp[i][buy][hold];
}
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
    int ans = solve(prices, n, dp, 0, 1, 2);
    return ans;
}