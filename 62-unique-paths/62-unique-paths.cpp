class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // formula: (m+n)!/m!n!
        // where m and n are no. of vertical and horizontal lines from source to sink
       
        // using dp
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};