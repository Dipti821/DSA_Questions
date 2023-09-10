//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int>ans;
        vector<pair<int,int>> adj[n+1];
        
        for(auto it : edges){
            adj[it[0]].push_back({it[1] ,it[2]});
            adj[it[1]].push_back({it[0] ,it[2]});
        }
        
        priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
        pq.push({0,1});
        
        vector<int>par(n+1);
        for(int i=1;i<=n;i++) par[i]=i;
        
        vector<int> dist(n+1,1e9);
        dist[1]=0;
        
        while(!pq.empty()){
           auto it= pq.top();
           int node=it.second;
           int dis=it.first;
           pq.pop();
           
           for(auto j: adj[node]){
              if(dis+j.second<dist[j.first]){
                  par[j.first]=node;
                  dist[j.first]=dis+j.second;
                  pq.push({dis+j.second, j.first});
              } 
           }
        }
        if(dist[n]==1e9) return {-1};
        
        int node=n;
        while(par[node]!=node){
            ans.push_back(node);
            node=par[node];
        }
        ans.push_back(node);
        reverse(ans.begin() ,ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends