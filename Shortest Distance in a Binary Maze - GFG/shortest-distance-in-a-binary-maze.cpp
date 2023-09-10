//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[source.first][source.second]=0;
        
        queue<pair<int ,pair<int,int>>> q;
        q.push({0 ,{source.first ,source.second}});
        
        int dx[4]={-1,0,+1,0};
        int dy[4]={0, +1, 0, -1};
        
        if(source==destination) return 0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            for(int i=0;i<4;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] && 1+dis<dist[nr][nc]){
                    dist[nr][nc]=1+dis;
                    if(nr==destination.first && nc==destination.second) return 1+dis;
                    q.push({1+dis ,{nr,nc}});
                }
            }
        }
        return -1;
        
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends