//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int i, int n)
    {
        vis[i] = 1;
        for(int j = 0; j < n; j++)
        {
            if(adj[i][j] == 1 && vis[j] == -1)
            {
                dfs(adj, vis, j, n);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) 
    {
        int n = adj.size();
        vector<int> vis(n, -1);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == -1)
            {
                ans++;
                dfs(adj, vis, i, n);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends