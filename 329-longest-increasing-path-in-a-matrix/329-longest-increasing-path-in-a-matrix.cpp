class Solution {
    
public:
    
    bool check(int i, int j ,int row , int col){
        return (i>=0 && i<row && j>=0 && j<col);
    }
    
    int cal(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j, int row, int col){
        
      if(!check(i , j, row, col)) return 0;
        
      if(dp[i][j]!=-1)
          return dp[i][j];
        
      int c1=0,c2=0,c3=0,c4=0;
      if(check(i+1 , j, row, col) && matrix[i+1][j]>matrix[i][j])
          c1=cal(matrix ,dp , i+1 , j, row, col);
        
      if(check(i-1 , j, row, col) && matrix[i-1][j]>matrix[i][j])
          c2=cal(matrix ,dp , i-1 , j, row, col);
        
      if(check(i , j+1, row, col) && matrix[i][j+1]>matrix[i][j])
          c3=cal(matrix ,dp , i , j+1, row, col);
        
      if(check(i , j-1, row, col) && matrix[i][j-1]>matrix[i][j])
          c4=cal(matrix ,dp , i , j-1, row, col);
        
      dp[i][j]=1+max({c1,c2,c3,c4});
      return dp[i][j];
         
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int ans=1;
        
        vector<vector<int>> dp(row, vector<int>(col,-1));
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dp[i][j]==-1)
                    ans=max(ans , cal(matrix,dp,i,j,row,col));
            }
        }
        return ans;
    }
};