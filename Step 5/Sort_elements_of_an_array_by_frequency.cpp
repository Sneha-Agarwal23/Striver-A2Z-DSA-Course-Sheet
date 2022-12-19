#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for(int i = 0; i < n; i++)
	    {
	        cin>>v[i];
	    }
	    unordered_map<int, int> m;
	    for(int i = 0; i < n; i++)
	    {
	        m[v[i]]++;
	    }
	    priority_queue<pair<int,int>> pq;
	    for(auto i : m)
	    {
	        pq.push({i.second,-1*( i.first)}); 
	    }
	    while(!pq.empty())
	    {
	        int x = pq.top().first;
	        int y = -1 * (pq.top().second);
	        for(int i = 0; i < x; i++)
	        {
	            cout<<y<<" ";
	        }
	        pq.pop();
	    }
	    cout<<endl;
	    
	    
	}
}