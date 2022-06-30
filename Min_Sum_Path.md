## Problem Statement:

Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns. Each point in the grid has some cost associated with it.
Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) which minimizes the sum of the cost of all the numbers along the path. You need
to tell the minimum sum of that path.
  
## Code:
 
~~~~~~
  int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    
    vector<int>prev(m,10000009);
    
    for(int i=0;i<n;i++){
        vector<int>temp(m,10000009);
        for(int j=0;j<m;j++){
            if(i==0 && j==0)temp[0]=grid[0][0];
            else{
            temp[j]=min(prev[j],j==0?10000009:temp[j-1])+grid[i][j];
            }
        } 
          prev=temp;
    }
    return prev[m-1];
}
~~~~~~
