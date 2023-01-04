#include <bits/stdc++.h> 

int solve(vector<int> &num, int tar, vector<vector<int>>& dp, int sum, int n)
{
    if(tar < sum)
        return 0;
    if(n < 0)
    {
        if(tar == sum)
            return 1;
        else
            return 0;
    }
    
    if(dp[n][sum] != -1)
        return dp[n][sum];
    
    int take = solve(num, tar, dp, sum + num[n], n-1);
    int nottake = solve(num, tar, dp, sum, n-1);
    dp[n][sum] = take + nottake;
    return dp[n][sum];
    
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, -1));
    int ans = solve(num, tar, dp, 0, n-1);
    return ans;
}