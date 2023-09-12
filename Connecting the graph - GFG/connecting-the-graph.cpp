//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Disjoint{
    public:
    vector<int> par, rank;
    
    Disjoint(int n){
        par.resize(n+1);
        rank.resize(n+1 ,0);
        
        for(int i=0;i<=n;i++)
        par[i]=i;
    }
    
    int findPar(int node){
        if(par[node]==node) return node;
        return par[node]=findPar(par[node]);
    }
    
    void unionByRank(int u ,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        
        if(ulp_u==ulp_v) return;
        
        if(rank[ulp_u]<rank[ulp_v])
        par[ulp_u]=ulp_v;
        else if(rank[ulp_u]>rank[ulp_v])
        par[ulp_v]=ulp_u;
        else{
           par[ulp_v]=ulp_u;
           rank[ulp_u]++;
        }
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        
        Disjoint ds(n);
        int edges=0 ,cnt=0;
            for(auto it : edge){
                if(ds.findPar(it[0])!=ds.findPar(it[1])){
                    ds.unionByRank(it[0] ,it[1]);
                }
                else
                edges++;
            }
            
            for(int i=0;i<n;i++){
                if(ds.par[i]==i)
                cnt++;
            }
            
            if(edges>=cnt-1) return cnt-1;
            else return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends