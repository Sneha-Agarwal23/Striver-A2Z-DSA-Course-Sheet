#include<bits/stdc++.h>
int dp[101][101];

int solve(vector<int> &arr, int i, int j)
{
    if(i >= j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int m = INT_MAX;
    for(int k = i; k <= j-1; k++)
    {
        int temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
        m = min(m, temp);
    }
    dp[i][j] = m;
    return dp[i][j];
        
}
int matrixMultiplication(vector<int> &arr, int N)
{
    memset(dp, -1, sizeof(dp));
    int ans = solve(arr, 1, N-1);
    return ans;
}