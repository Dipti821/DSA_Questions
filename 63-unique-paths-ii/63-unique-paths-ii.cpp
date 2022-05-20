class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
        if(obstacleGrid[0][0]==1)
           return 0;
        
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==0){
                    dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j];
                }
            }
        }
        return dp[m][n];
    }
};