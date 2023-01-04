#include <bits/stdc++.h> 
int solve(vector<int>& arr, int n, vector<int>& sum, int start, vector<vector<int>>& dp)
{
    if(n == 0)
    {
        sum.push_back(start);
        return 0;
    }
    if(dp[n][start] != -1)
        return dp[n][start];
    
    int take = solve(arr, n-1, sum, start + arr[n-1], dp);
    int nottake = solve(arr, n-1, sum, start, dp);
    return dp[n][start] = start;
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
    vector<int> sum;
    int start = 0;
    int tsum = 0;
    for(int i = 0;i < n;i++)
    {
        tsum += arr[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(tsum+1,-1));
    solve(arr,n,sum,start,dp);
    int minimum = INT_MAX;
    for(int i = 0; i < sum.size();i++)
    {
        int m = abs(tsum - sum[i]);
        int diff = abs(m- sum[i]);
        minimum = min(diff,minimum); 
    }
    return minimum;
}
