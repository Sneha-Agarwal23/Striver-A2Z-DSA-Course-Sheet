#include <bits/stdc++.h> 
int lcs(string &str1, string &str2)
{
    /*int n = str1.length();
    int m = str2.length();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int k = 0;
            while((i+k) < n && (j+k) < m && str1[i+k] == str2[j+k])
            {
                k++;
            }
            ans = max(ans, k);
        }
    }
    return ans;*/
    
    int n = str1.length();
    int m = str2.length();
    int ans = 0;
    vector<vector<int>> dp(n+1, vector<int> (m+1));
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}