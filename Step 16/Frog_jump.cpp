#include <bits/stdc++.h> 
/*int solve(int n, vector<int>& dp, vector<int> &heights)
{
    if(n == 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    
    int jump1 = solve(n-1, dp, heights) + abs(heights[n] - heights[n-1]);
    int jump2 = INT_MAX;
    if(n > 1)
        jump2 = solve(n-2, dp, heights) + abs(heights[n] - heights[n-2]);
    
    return dp[n] = min(jump1, jump2);
}*/
/*int solve(int n, vector<int> &heights,vector<int>& dp)
{
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        int jump1 = dp[i-1] + abs(heights[i] - heights[i-1]);
        int jump2 = INT_MAX;
        if(i > 1)
            jump2 = dp[i-2] + abs(heights[i] - heights[i-2]);
        
        dp[i] = min(jump1, jump2);
    }
    return dp[n];
}*/
int frogJump(int n, vector<int> &heights)
{
    //vector<int> dp(n+1, -1);
    //return solve(n-1,heights,dp);
    //return solve(n-1, dp, heights);
    
    int temp1 = 0, temp2 = 0;
    for(int i = 1; i < n; i++)
    {
        int jump1 = temp2 + abs(heights[i] - heights[i-1]);
        int jump2 = INT_MAX;
        if(i > 1)
            jump2 = temp1 + abs(heights[i] - heights[i-2]);
        
        int temp3 = min(jump1, jump2);
        temp1 = temp2;
        temp2 = temp3;
    }
    return temp2;
}