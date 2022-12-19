class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int row, int col, int i, int j)
    {
        if(i == row || j == col || i < 0 || j < 0 || vis[i][j] == 1 || board[i][j] != 'O')
            return;
        
        vis[i][j] = 1;
        board[i][j] = 'S';
        dfs(board, vis, row, col, i+1, j);
        dfs(board, vis, row, col, i-1, j);
        dfs(board, vis, row, col, i, j+1);
        dfs(board, vis, row, col, i, j-1);
    }
    void solve(vector<vector<char>>& board)
    {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> vis(row, vector<int> (col, 0));
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(board[i][j] == 'O' &&(i == row-1 || j == col-1 || i == 0 || j == 0))
                    dfs(board, vis, row, col, i, j);
            }
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(board[i][j] == 'S')
                    board[i][j] = 'O';
                else if(board[i][j] = 'O')
                    board[i][j] = 'X';
            }
        }
        
    }
};