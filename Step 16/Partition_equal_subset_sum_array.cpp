#include<bits/stdc++.h>
bool solve(int i, vector<int> &arr, int n, int target, vector<vector<int>> & dp)
{
    if(i >= n)
        return false;
    if(target < 0)
        return false;
    if(target == 0)
        return true;
    if(dp[i][target] != -1)
        return dp[i][target];
    
    bool take = solve(i+1, arr, n, target - arr[i], dp);
    bool nottake = solve(i+1, arr, n, target, dp);
    
    return dp[i][target] = take or nottake;
}
bool canPartition(vector<int> &arr, int n)
{
	int total = 0;
    for(int i = 0; i < n; i++)
        total += arr[i];
    if(total % 2 != 0)
        return false;
    int target = total/2;
    vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
    return solve(0, arr, n, target, dp);
}
