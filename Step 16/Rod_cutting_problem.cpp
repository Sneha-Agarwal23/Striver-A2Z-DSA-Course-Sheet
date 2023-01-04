#include<bits/stdc++.h>
int solve(vector<int> &price, int n, int i, vector<vector<int>>& dp)
{
    if(n == 0)
        return 0;
    if(i == 0)
        return n * price[0];
    if(dp[i][n] != -1)
        return dp[i][n];
    
    int take = INT_MIN;
    if(i+1 <= n)
        take = price[i] + solve(price, n-(i+1), i, dp);
    int nottake = solve(price, n, i-1, dp);
    dp[i][n] = max(take, nottake);
    return dp[i][n];
}
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    return solve(price, n, n-1,dp);
}
