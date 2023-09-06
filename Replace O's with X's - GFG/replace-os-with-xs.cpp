//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int dr[4]={-1,0,+1,0};
    int dc[4]={0,+1,0,-1};
    void dfs(int row ,int col ,int n, int m ,vector<vector<bool>> &vis,vector<vector<char>> &mat){
        vis[row][col]=1;
        
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O')
            dfs(nrow ,ncol ,n , m, vis, mat);
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        // first ans last row
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O' && !vis[0][i])
            dfs(0,i,n,m,vis,mat);
            if(mat[n-1][i]=='O' && !vis[n-1][i])
             dfs(n-1,i,n,m,vis,mat);
        }
        
        //first and last column
          for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && !vis[i][0])
            dfs(i,0,n,m,vis,mat);
            if(mat[i][m-1]=='O' && !vis[i][m-1])
            dfs(i,m-1,n,m,vis,mat);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j])
                mat[i][j]='X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends