class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.'));
        vector<int>leftrow(n, 0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1, 0);
        solveNQueens(0, board, res, leftrow, upperDiagonal, lowerDiagonal, n);
        return res;
    }
    private:
    // void solveNQueens(vector<vector<string>> &res,vector<string> &board, int row, int &n) {
    //    TC: O(N!*N) SC: O(N^2) 
    // if (row == n) {
    //         res.push_back(board);
    //         return;
    //     }
    //     for (int col = 0; col != n; ++col)
    //         if (isValid(board, row, col, n)) {
    //             board[row][col] = 'Q';
    //             solveNQueens(res, board, row + 1, n);
    //             board[row][col] = '.';
    //         }
    // }
    // bool isValid(vector<string> &board, int row, int col, int &n) {
    //     //check if the column had a queen before.
    //     for (int i = 0; i != row; ++i)
    //         if (board[i][col] == 'Q')
    //             return false;
    //     //check if the 45° diagonal had a queen before.
    //     for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
    //         if (board[i][j] == 'Q')
    //             return false;
    //     //check if the 135° diagonal had a queen before.
    //     for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
    //         if (board[i][j] == 'Q')
    //             return false;
    //     return true;
    // }
    
    // optimise using hashing
    void solveNQueens(int col, vector<string> &board, vector<vector<string>>&ans, vector<int> &leftrow, vector<int>&upperDiagonal, vector<int>&lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          solveNQueens(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
    }
    
};


