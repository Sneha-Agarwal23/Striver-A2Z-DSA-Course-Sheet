//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    /*bool flag = false;
    void dfs(int i, vector<int>& vis, vector<int> adj[], int parent)
    {
        vis[i] = 1;
        for(auto j : adj[i])
        {
            if(vis[j] == 0)
                dfs(j, vis, adj, i);
            else if(j != parent)
                flag = true;
        }
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i, vis, adj, -1);
            }
        }
        return flag;
    }*/
    
    bool isCycle(int V, vector<int> adj[])
    {
        for(int i = 0; i < V; i++)
        {
            vector<int> vis(V, 0);
            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                int x = q.front();
                q.pop();
                if(vis[x] == 1)
                    return true;
                vis[x] = 1;
                for(auto j : adj[x])
                {
                    if(vis[j] == 0)
                        q.push(j);
                }
            }
        }
        return false;
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends