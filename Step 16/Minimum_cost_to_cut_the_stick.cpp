#include <bits/stdc++.h> 
int solve(int n, vector<int>&cuts, vector<vector<int>>& dp, int start, int end)
{
    if(end - start <= 1)
        return 0;
    if(dp[start][end] != -1)
        return dp[start][end];
    
    int totalcost = INT_MAX;
    for(int i = start + 1; i < end; i++)
    {
        int x = solve(n, cuts, dp, start, i);
        int y = solve(n, cuts, dp, i, end);
        totalcost = min(totalcost, x+y);
    }
    totalcost += cuts[end] - cuts[start];
    return dp[start][end] = totalcost;
}
int cost(int n, int c, vector<int> &cuts)
{
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c+2, vector<int> (c+2, -1));
    int ans = solve(n, cuts, dp, 0, c+1);
    return ans;
}