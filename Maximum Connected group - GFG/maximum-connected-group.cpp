//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet {
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        int dr[4]={-1 ,0 ,+1 ,0};
        int dc[4]={0 ,+1 ,0 ,-1};
        
        DisjointSet ds(n*m);
       
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                int node=i*m+j; 
                  for(int k=0;k<4;k++){
                      int adji=i+dr[k];
                      int adjj=j+dc[k];
                      int adjno=adji*m+adjj;
                      
                      if(adji>=0 && adji<n && adjj>=0 && adjj<m && grid[adji][adjj] ){
                          ds.unionBySize(node ,adjno);
                      }
                  }
                }
            }
        }
        
       int ans=0; 
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]==0){
                   
                   int cnt=1;
                   set<int>s;
                   for(int k=0;k<4;k++){
                      int adji=i+dr[k];
                      int adjj=j+dc[k];
                      int adjno=adji*m+adjj;
                      
                      if(adji>=0 && adji<n && adjj>=0 && adjj<m && grid[adji][adjj] ){
                        s.insert(ds.findUPar(adjno));
                      }
                  } 
                  for(auto it: s){
                      cnt+=ds.size[it];
                  }
                  ans=max(ans,cnt);
               }
           }
       }
       
       for(int i=0;i<n*m;i++){
           ans=max(ans,ds.size[ds.findUPar(i)]);
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends