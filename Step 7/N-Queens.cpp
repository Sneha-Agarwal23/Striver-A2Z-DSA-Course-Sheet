class Solution {
public:
    bool check(vector<string> &board, int row, int col)
    {
        int n = board.size();
        for(int i = 0; i < n; i++)
        {
            if(board[i][col] == 'Q')
                return false;
            if(row-i >= 0 && col-i >= 0 && board[row-i][col-i] == 'Q')
                return false;
            if(row+i < n && col- i >= 0 && board[row+i][col-i] == 'Q')
                return false;
            if(row - i >= 0 && col+i < n && board[row-i][col+i] == 'Q')
                return false;
            if(row+i < n && col+i < n && board[row+i][col+i] == 'Q')
                return false;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans, vector<string> &board, int n, int row)
    {
        if(row == n)
        {
            ans.push_back(board);
            return;
        }
        for(int col = 0; col < n; col++)
        {
            if(check(board, row, col))
            {
                board[row][col] = 'Q';
                solve(ans, board, n, row+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(ans, board, n, 0);
        return ans;
    }
};