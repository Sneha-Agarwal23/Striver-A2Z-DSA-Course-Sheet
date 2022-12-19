//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int i, vector<int> adj[],vector<int> &vis, vector<int> &v)
    {
        vis[i] = 1;
        v[i] = 1;
        for(auto j : adj[i])
        {
            if(vis[j] == 0)
            {
                if(dfs(j, adj, vis, v) == true)
                    return true;
            }
            else if(v[j] == 1)
                return true;
        }
        v[i] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> v(V,0);
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
            {
                if(dfs(i, adj, vis, v) == true)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends