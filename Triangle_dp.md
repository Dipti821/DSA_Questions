## Problem Statement:

You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the top to the bottom row.
The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.
You can move only to the adjacent number of row below each step. For example, if you are at index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.

## Code:

~~~~~~

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    int dp[n][n];
    
    for(int j=0;j<n;j++)
        dp[n-1][j]=triangle[n-1][j];
    
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
           int d=triangle[i][j]+dp[i+1][j];
           int dg=triangle[i][j]+dp[i+1][j+1];
           dp[i][j]=min(d,dg);
        }
    }
    return dp[0][0];
}
~~~~~~

