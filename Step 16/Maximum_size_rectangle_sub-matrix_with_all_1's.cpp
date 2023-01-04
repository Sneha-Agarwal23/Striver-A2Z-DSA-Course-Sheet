#include<bits/stdc++.h>
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m)
{
    if(mat.empty() == true)
        return 0;
    vector<int> left(m, 0);
    vector<int> right(m, m);
    vector<int> height(m, 0);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int cleft = 0, cright = m;
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j] == 1)
                height[j]++;
            else
                height[j] = 0;
        }
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j] == 1)
                left[j] = max(left[j], cleft);
            else
            {
                left[j] = 0;
                cleft = j+1;
            }
        }
        for(int j = m-1; j >= 0; j--)
        {
            if(mat[i][j] == 1)
                right[j] = min(right[j], cright);
            else
            {
                right[j] = m;
                cright = j;
            }
        }
        for(int j = 0; j < m; j++)
        {
            ans = max(ans, height[j] * (right[j] - left[j]));
        }
    }
    return ans;
}