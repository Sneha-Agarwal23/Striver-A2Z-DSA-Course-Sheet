#include <bits/stdc++.h> 
int solve(string &str, vector<vector<int>>&dp,int start,int end)
{
    if(start >= end)
        return 0;
    if(dp[start][end] != -1)
        return dp[start][end];
    int a = 0;
    if(str[start] == str[end])
        a = solve(str,dp,start+1,end-1);
    else
    {
        int s = solve(str,dp,start+1,end);
        int e = solve(str,dp,start,end-1);
        
        a = 1 + min(s,e);
    }
    dp[start][end] = a;
    return a;
}
int minInsertion(string &str)
{
    int n = str.length();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    int ans = solve(str,dp, 0,n-1);
    return ans;
}