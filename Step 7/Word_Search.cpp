//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,vector<vector<int>> &dp, int i, int j, int k)
    {
        if(k == word.size())
            return true;
        
        if(i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && dp[i][j] == 0 && board[i][j] == word[k])
        {
            dp[i][j] = 1;
            if(solve(board, word, dp, i+1, j, k+1) || solve(board, word, dp, i, j+1, k+1) || 
            solve(board, word, dp, i-1, j, k+1) || solve(board, word, dp, i, j-1, k+1))
            {
                return true;
            }
            dp[i][j] = 0;
        }
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) 
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        int k = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(word[k] == board[i][j])
                {
                    if(solve(board, word, dp, i, j, k))
                        return true;
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends