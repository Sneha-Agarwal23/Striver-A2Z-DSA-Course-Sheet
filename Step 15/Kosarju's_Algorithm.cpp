//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void revdfs(int node, vector<int>& vis, vector<int> transpose[])
	{
	    vis[node] = 1;
	    for(auto i : transpose[node])
	    {
	        if(vis[i] == 0)
	            revdfs(i, vis, transpose);
	    }
	}
	void dfs(int src, vector<int>& vis, vector<int> adj[], stack<int>& s)
	{
	    vis[src] = 1;
	    for(auto i : adj[src])
	    {
	        if(vis[i] == 0)
	            dfs(i, vis, adj, s);
	    }
	    s.push(src);
	}
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> s;
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
                dfs(i, vis, adj, s);
        }
        
        vector<int> transpose[V];
        for(int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for(auto j : adj[i])
            {
                transpose[j].push_back(i);
            }
        }
        
        int ans = 0;
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            if(vis[node] == 0)
            {
                ans++;
                revdfs(node, vis, transpose);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends