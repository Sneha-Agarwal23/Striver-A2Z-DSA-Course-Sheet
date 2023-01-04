#include <bits/stdc++.h> 
int solve(string &a,int n, string &b, int m, vector<vector<int>>&dp)
{
    if(n == 0)
        return m;
    if(m == 0)
        return n;
    if(dp[n][m] != INT_MAX)
        return dp[n][m];
    if(a[n-1] == b[m-1])
    {
        dp[n][m] = 1 + solve(a,n-1,b,m-1,dp);
        return dp[n][m];
    }
    else
    {
        dp[n][m] = 1 + min(solve(a, n-1, b, m, dp), solve(a, n, b, m-1, dp));
        return dp[n][m];
    }
}
string backtrack(vector<vector<int>>&dp,string &a, string &b,int n,int m)
{
    string ans = "";
    while(n > 0 && m > 0)
    {
        if(a[n-1] == b[m-1])
        {
            ans += a[n-1];
            n--;
            m--;
        }
        else if(dp[n-1][m] < dp[n][m-1])
        {
            ans += a[n-1];
            n--;
        }
        else
        {
            ans += b[m-1];
            m--;
        }
    }
    while(n > 0)
    {
        ans += a[n-1];
        n--;
    }
    while(m > 0)
    {
        ans += b[m-1];
        m--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
string shortestSupersequence(string a, string b)
{
	int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
    solve(a, n, b, m, dp);
    return backtrack(dp,a,b,n,m);
}