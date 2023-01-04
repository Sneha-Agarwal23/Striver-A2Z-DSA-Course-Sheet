#include <bits/stdc++.h> 
bool comp(string &a,string &b)
{
    return a.length() < b.length();
}
int longestStrChain(vector<string> &arr)
{
    sort(arr.begin(), arr.end(),comp);
    unordered_map<string,int> m;
    int ans = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        int l = 1;
        for(int j = 0; j < arr[i].size();j++)
        {
            string s = arr[i].substr(0,j) + arr[i].substr(j+1);
            if(m.find(s) != m.end())
            {
                l = max(l, m[s] + 1);
            }
        }
        m[arr[i]] = l;
        ans = max(ans, l);
    }
    return ans;
}