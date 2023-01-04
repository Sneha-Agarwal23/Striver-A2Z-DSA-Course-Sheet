#include<bits/stdc++.h>
long solve(long *values, int n, vector<vector<long>>& dp, int i, int buy)
{
    if(i == n)
        return 0;
    if(dp[i][buy] != -1)
        return dp[i][buy];
    
    if(buy == 1)
    {
        long take = solve(values, n, dp, i+1, 0) - values[i];
        long nottake = solve(values, n, dp, i+1, 1);
        dp[i][buy] = max(take, nottake);
    }
    else
    {
        long take = values[i] + solve(values, n, dp, i+1, 1);
        long nottake = solve(values, n, dp, i+1, 0);
        dp[i][buy] = max(take, nottake);
    }
    return dp[i][buy];
        
}
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n, vector<long> (2, -1));
    long ans = solve(values, n, dp, 0, 1);
    return ans;
}