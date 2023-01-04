#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices)
{
    int n = prices.size();
    int minprice = prices[0], maxprofit = 0;
    for(int i = 1; i < n; i++)
    {
        minprice = min(minprice, prices[i]);
        maxprofit = max(maxprofit, prices[i] - minprice);
    }
    return maxprofit;
    
}