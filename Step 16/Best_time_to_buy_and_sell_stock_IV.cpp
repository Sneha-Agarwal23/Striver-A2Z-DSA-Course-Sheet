#include <bits/stdc++.h> 
int solve(vector<int> &prices, int n, int k, vector<vector<vector<int>>>& dp, int i, int buy)
{
    if(i == n || k == 0)
        return 0;
    if(dp[i][k][buy] != -1)
        return dp[i][k][buy];
    
    if(buy == 0)
    {
        int sell = solve(prices, n, k, dp, i+1, 0);
        int b = solve(prices, n, k,dp, i + 1, 1) - prices[i];
        dp[i][k][buy] = max(sell,b);
    }
    else
    {
        int nb = solve(prices , n, k, dp, i+1 , 1);
        int b = solve(prices , n , k-1 ,dp, i+1 , 0) + prices[i];
        dp[i][k][buy] = max(nb, b);
    }
    return dp[i][k][buy];
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
    int ans = solve(prices, n, k, dp, 0, 0);
    return ans;
}