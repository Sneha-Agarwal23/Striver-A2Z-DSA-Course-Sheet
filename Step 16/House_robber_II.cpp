#include <bits/stdc++.h> 
long long int solve(vector<int>& arr)
{
    int n = arr.size();
    long long int temp1 = arr[0];
    long long int temp2 = 0;
    for(int i = 1; i < n; i++)
    {
        long long int pick = arr[i];
        if(i > 1)
            pick += temp2;
        long long int notpick = temp1;
        long long int temp3 = max(pick, notpick);
        temp2 = temp1;
        temp1 = temp3;
    }
    return temp1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    vector<int> arr1;
    vector<int> arr2;
    if(n == 1)
        return valueInHouse[0];
    for(int i = 0; i < n; i++)
    {
        if(i != 0)
            arr1.push_back(valueInHouse[i]);
        if(i != n-1)
            arr2.push_back(valueInHouse[i]);
    }
    long long int x = solve(arr1);
    long long int y = solve(arr2);
    return max(x,y);
}