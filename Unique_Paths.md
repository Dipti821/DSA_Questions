## Problem Statement:

You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, which is the bottom-right cell of the same matrix. 
Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’
, your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i] [j], you can move to either MATRIX[i + 1][j] 
or MATRIX[i][j + 1].


## Code:

~~~~~~
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
    int dp[m][n];
    for(int i=0;i<n;i++)
        dp[0][i]=1;
    for(int i=0;i<m;i++)
        dp[i][0]=1;
    
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
           dp[i][j]=dp[i-1][j]+dp[i][j-1];
        } 
    }
    return dp[m-1][n-1];
}


// Space Optimisation


#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
    vector<int>prevrow(n,0);
    for(int i=0;i<m;i++){
        vector<int>temp(n,0);
        for(int j=0;j<n;j++){
            if(i==0 && j==0) temp[j]=1;
            else if(j==0) temp[j]=prevrow[j];
            else
            temp[j] =temp[j-1]+prevrow[j];
        } 
        prevrow=temp;
    }
    return prevrow[n-1];
}
~~~~~~

## Reference:
- [Codstudio](https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos)
