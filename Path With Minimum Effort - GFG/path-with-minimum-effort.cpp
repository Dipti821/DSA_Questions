//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size();
        int m=heights[0].size();
        
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        
        int dr[4]={-1 , 0,+1 ,0};
        int dc[4]={ 0,+1 , 0 ,-1};
        
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            if(r==n-1 && c==m-1) return diff;
            
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newEffort=max(abs(heights[nr][nc] -heights[r][c]) ,diff);
                    if(newEffort<dist[nr][nc]){
                        dist[nr][nc]=newEffort;
                        pq.push({newEffort ,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends