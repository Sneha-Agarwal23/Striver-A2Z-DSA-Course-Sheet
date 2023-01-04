#include <bits/stdc++.h> 
int maximumProfit(int n, int fee, vector<int> &prices)
{
    int p1 = 0;
    int p2 = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int x = prices[i];
        p1 = max(p1,p2 + x);
        p2 = max(p2,p1 - fee - x);
    }
    return p1;
}
