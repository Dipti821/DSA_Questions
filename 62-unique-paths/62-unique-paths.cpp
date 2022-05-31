class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // formula: (m+n)!/m!n!
        // where m and n are no. of vertical and horizontal lines from source to sink
        int N=m+n-2;
        int r=m-1;
        double res=1;
        for(int i=1;i<=r;i++)
            res*=(double)(N-r+i)/i;
        return (int)round(res);
        
        // Brute Force: Recursion TC: exponential SC: exponential
        // return countPaths(0,0,m,n);
       
        // using dp
        // vector<vector<int>> dp(m, vector<int>(n, 1));
        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++) {
        //         dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        //     }
        // }
        // return dp[m - 1][n - 1];
    }
//     int countPaths(int i , int j , int m ,int n){
//         if(i==m-1 && j==n-1) return 1;
//         if(i>=m || j>=n) return 0;
//         else return countPaths(i+1,j,m,n)+countPaths(i,j+1,m,n); 
        
//     }
};