## Problem Statement:

You have been given an N*M matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell
in the last row.
From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. So from a particular cell (row, col), we can move in three
directions i.e.

Down: (row+1,col)

Down left diagonal: (row+1,col-1)

Down right diagonal: (row+1, col+1)


## Solution:

~~~~~~


int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
      int n=matrix.size();
        int m=matrix[0].size();
        vector<int>dp(m);
        for(int j=0;j<m;j++)
            dp[j]=matrix[0][j];
        
        for(int i=1;i<n;i++){
             vector<int>temp(m);
            for(int j=0;j<m;j++){
                int rd=j+1<m?matrix[i][j]+dp[j+1]:-1e8;
                int ld=j-1>=0?matrix[i][j]+dp[j-1]:-1e8;
                int d=matrix[i][j]+dp[j];
                
                temp[j]=max(rd,max(ld,d));
            }
            dp=temp;
        }
        int ans=dp[0];
        for(int j=1;j<m;j++)
            ans=max(ans,dp[j]);
        
        return ans;
}
~~~~~~
