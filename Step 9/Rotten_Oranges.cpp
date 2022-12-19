//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        int dir[4][4] = {{-1, 0} , {0, 1}, {1, 0}, {0, -1}};
        vector<vector<int>> vis(n, vector<int> (m, 0));
        while(!q.empty())
        {
            int x = q.size();
            bool flag = false;
            for(int i = 0; i < x; i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                vis[row][col] = 1;
                for(int j = 0; j < 4; j++)
                {
                    int a = row + dir[j][0];
                    int b = col + dir[j][1];
                    if(a < 0 || b < 0 || a >= n || b >= m || grid[a][b] == 0 || vis[a][b] == 1)
                        continue;
                    if(grid[a][b] == 1)
                    {
                        flag = true;
                        q.push({a, b});
                        grid[a][b] = 2;
                    }
                    
                    
                }
            }
            if(flag == true)
                ans++;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends