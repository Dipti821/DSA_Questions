//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    int dr[4]={-1,0,+1,0};
    int dc[4]={0,+1,0,-1};
    void dfs(int row ,int col ,int n, int m ,vector<vector<bool>> &vis,vector<vector<int>> &grid){
        vis[row][col]=1;
        
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            dfs(nrow ,ncol ,n , m, vis, grid);
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        // first ans last row
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && !vis[0][i])
            dfs(0,i,n,m,vis,grid);
            if(grid[n-1][i]==1 && !vis[n-1][i])
             dfs(n-1,i,n,m,vis,grid);
        }
        
        //first and last column
          for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0])
            dfs(i,0,n,m,vis,grid);
            if(grid[i][m-1]==1 && !vis[i][m-1])
            dfs(i,m-1,n,m,vis,grid);
        }
        
        int ans=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) ans++;
                if(vis[i][j])
                ans--;
            }
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends