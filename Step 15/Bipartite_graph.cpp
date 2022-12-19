//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int V, vector<int>adj[], vector<int>& vis, int i)
    {
        if(vis[i] == -1)
            vis[i] = 1;
        
        for(auto x : adj[i])
        {
            if(vis[x] == -1)
            {
                vis[x] = 1 - vis[i];
                if(dfs(V, adj, vis, x) == false)
                    return false;
            }
            else if(vis[x] == vis[i])
                return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[])
	{
	    vector<int> vis(V, -1);
	    for(int i = 0; i < V; i++)
	    {
	        if(vis[i] == -1)
	        {
	            if(dfs(V, adj, vis, i) == false)
	                return false;
	        }
	    }
	    return true;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends