#include<bits/stdc++.h>
/*int solve(int arr[], int n, vector<vector<int>>& dp, int prev, int cur)
{
    if(cur == n)
        return 0;
    if(dp[prev+1][cur] != -1)
        return dp[prev+1][cur];
    int take = 0;
    if(prev < 0 || arr[cur] > arr[prev])
    {
        take = 1 + solve(arr, n, dp, cur, cur+1);
    }
    int nottake = solve(arr, n, dp, prev, cur+1);
    dp[prev+1][cur] = max(take, nottake);
    return dp[prev+1][cur];
}*/
int longestIncreasingSubsequence(int arr[], int n)
{
    /*int ans = 0;
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    ans = solve(arr, n, dp, -1, 0);
    return ans;*/
    
    int ans = 0;
    int dp[n];
    for(int i = 0; i < n; i++)
    {
        int p = lower_bound(dp,dp+ans,arr[i]) - dp;
        dp[p] = arr[i];
        if(p == ans)
            ans++;
    }
    return ans;
}
