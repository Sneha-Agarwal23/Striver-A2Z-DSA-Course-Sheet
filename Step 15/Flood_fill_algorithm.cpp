//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int color, int sr, int sc, int newColor, vector<vector<int>>& image, vector<vector<int>>& ans, 
    int row, int col)
    {
        if(sr < 0 || sc < 0 || sr > row-1 || sc > col-1 || image[sr][sc] == -1 || image[sr][sc] != color)
            return;
        
        image[sr][sc] = -1;
        ans[sr][sc] = newColor;
        
        dfs(color, sr+1, sc, newColor, image, ans, row, col);
        dfs(color, sr-1, sc, newColor, image, ans, row, col);
        dfs(color, sr, sc+1, newColor, image, ans, row, col);
        dfs(color, sr, sc-1, newColor, image, ans, row, col);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int color = image[sr][sc];
        int row = image.size();
        int col = image[0].size();
        vector<vector<int>> ans = image;
        dfs(color,sr,sc,newColor,image,ans,row,col);
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends