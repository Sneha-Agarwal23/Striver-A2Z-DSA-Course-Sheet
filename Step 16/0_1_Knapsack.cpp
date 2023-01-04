#include <bits/stdc++.h> 
int solve(vector<int> weight, vector<int> value, int i, int n, int maxWeight, vector<vector<int>>& dp)
{
    if(maxWeight == 0 || i == n)
        return 0;
    if(dp[maxWeight][i] != -1)
        return dp[maxWeight][i];
    
    int take = 0;
    if(maxWeight >= weight[i])
        take =value[i] + solve(weight, value, i+1, n, maxWeight - weight[i], dp);
    int nottake = solve(weight, value, i+1, n, maxWeight, dp);
    return dp[maxWeight][i] = max(take, nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(maxWeight+1, vector<int> (n+1, -1));
    return solve(weight, value, 0, n, maxWeight, dp);
}