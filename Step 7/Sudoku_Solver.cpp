class Solution {
public:
    bool solve(vector<vector<char>>& board, int i, int j)
    {
        if(i == 9)
            return true;
        if(j == 9)
            return solve(board, i+1, 0);
        if(board[i][j] != '.')
            return solve(board, i, j+1);
        for(char c = '1'; c <= '9'; c++)
        {
            if(check(board, i, j, c) == true)
            {
                board[i][j] = c;
                if(solve(board, i, j+1) == true)
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    
    bool check(vector<vector<char>>& board, int i, int j, char value)
    {
        int row = i - i%3;
        int col = j - j%3;
        for(int x = 0; x < 9; x++)
        {
            if(board[x][j] == value)
                return false;
        }
        for(int y = 0; y < 9; y++)
        {
            if(board[i][y] == value)
                return false;
        }
        for(int x = 0; x < 3; x++)
        {
            for(int y = 0; y < 3; y++)
            {
                if(board[x+row][y+col] == value)
                    return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board, 0, 0);
        
    }
};