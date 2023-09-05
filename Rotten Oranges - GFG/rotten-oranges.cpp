//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int freshOrange=0;
        
        vector<vector<int>> vis(n ,vector<int>(m,0));
        queue<pair<pair<int,int> ,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2;
                }
                if(grid[i][j]==1)
                freshOrange++;
            }
        }
        
        
        int tm=0;
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            
            tm=max(tm,t);
            
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=2 && grid[nr][nc]==1){
                    q.push({{nr,nc} ,t+1});
                    vis[nr][nc]=2;
                    freshOrange--;
                }
            }
            
        }
        if(!freshOrange) return tm;
        else return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends