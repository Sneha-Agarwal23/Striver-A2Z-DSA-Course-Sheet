/*int solve(int n,int l, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if(dp[n][l] != -1)
        return dp[n][l];
    
    int m = 0;
    for(int i = 0; i < 3; i++)
    {
        if(i != l)
        {
            if(n == 1)
                m = max(m, points[0][i]);
            else
            {
                m = max(m, points[n-1][i] + solve(n-1, i, points, dp));
            }
        }
    }
    dp[n][l] = m;
    return dp[n][l];
}*/
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n+1, vector<int> (4, -1));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            dp[i][j] = 0;
            for(int k = 0; k < 3; k++)
            {
                if(k != j)
                {
                    if(i == 0)
                        dp[i][j] = max(dp[i][j], points[0][k]);
                    else
                        dp[i][j] = max(dp[i][j], points[i][k] + dp[i-1][k]);
                }
            }
        }
    }
    return dp[n-1][3];
    //return solve(n,3, points, dp);
}