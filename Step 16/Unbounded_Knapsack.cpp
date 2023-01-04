#include <bits/stdc++.h> 
int solve(int n, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>>& dp)
{
    if(dp[w][n] != -1)
        return dp[w][n];
    if(n == 0 || w == 0)
        return 0;
    if(weight[n-1] > w)
        dp[w][n] = solve(n-1, w, profit, weight, dp);
    else
        dp[w][n] = max(profit[n-1] + solve(n, w - weight[n-1], profit, weight, dp) , solve(n-1, w, profit, weight, dp));
    return dp[w][n];
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    /*if( n == 0 || w == 0)
        return 0;
    
    if(weight[n-1]> w)
    {
        return unboundedKnapsack(n-1,w,profit,weight);
    }
    else
    {
        return max(profit[n-1] + unboundedKnapsack(n, w - weight[n-1], profit, weight) , unboundedKnapsack(n-1, w, profit, weight));
    }*/
    
    vector<vector<int>> dp(w+1, vector<int> (n+1, -1));
    return solve(n, w, profit, weight, dp);
}
