//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool check(int index, int n, bool graph[101][101], int i, vector<int> &color)
    {
        for(int j = 0; j < n; j++)
        {
            if(graph[index][j] && i == color[j])
                return false;
        }
        return true;
    }
    bool solve(int index, int m, int n, bool graph[101][101], vector<int> &color)
    {
        if(index == n)
            return true;
        
        for(int i = 1; i <= m; i++)
        {
            if(check(index, n, graph, i, color))
            {
                color[index] = i;
                if(solve(index+1, m, n, graph, color))
                    return true;
                color[index] = -1;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) 
    {
        vector<int> color(n, -1);
        return solve(0, m, n, graph, color);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends