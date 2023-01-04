#include <bits/stdc++.h> 
int solve(vector<int>& arr, vector<vector<int>>& dp, int d, int total, int sum, int n)
{
    if(n < 0)
    {
        if(total - 2 * sum == d)
            return 1;
        else
            return 0;
    }
    if(dp[n][sum] != -1)
        return dp[n][sum];
    int take = solve(arr, dp, d, total, sum + arr[n], n-1);
    int nottake = solve(arr, dp, d, total, sum, n-1);
    dp[n][sum] = (take + nottake) % 1000000007;
}
int countPartitions(int n, int d, vector<int> &arr)
{
    int total = 0;
    for(int i = 0; i < n; i++)
        total += arr[i];
    vector<vector<int>> dp(n, vector<int> (total+1, -1));
    int ans = solve(arr, dp, d, total, 0, n-1);
    return ans;
}


