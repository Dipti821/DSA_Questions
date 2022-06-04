class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.'));
        solveNQueens(res, board, 0, n);
        return res;
    }
    private:
    void solveNQueens(vector<vector<string>> &res,vector<string> &board, int row, int &n) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                solveNQueens(res, board, row + 1, n);
                board[row][col] = '.';
            }
    }
    bool isValid(vector<string> &board, int row, int col, int &n) {
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (board[i][col] == 'Q')
                return false;
        //check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (board[i][j] == 'Q')
                return false;
        return true;
    }
    
};


