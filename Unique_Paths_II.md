## Problem Statement:

Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to reach the right-bottom cell from the top-left cell. A cell in the given maze has
a value '-1' if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. Since the answer can be large,
print it modulo 10^9 + 7.


## Code:

~~~~~~
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>>dp(n,vector<int>(m,0));
    if(mat[0][0]==-1) return 0;
  
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]!=-1){
            if(i==0 && j==0)dp[0][0]=1;
            else
            dp[i][j]=((i!=0?dp[i-1][j]:0)+(j!=0?dp[i][j-1]:0))%(1000000007);
            }
        } 
    }
    return dp[n-1][m-1];
}
~~~~~~

### Note:
You can further space optimised it.
