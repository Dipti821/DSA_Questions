//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> rank ,par,size;
    
    public:
    DisjointSet(int n){
       rank.resize(n+1 ,0);
       par.resize(n+1);
       size.resize(n+1);
       
       for(int i=0;i<=n;i++){
           par[i]=i;
           size[i]=1;
       }
       
    }
    
    int findPar(int node){
        if(par[node]==node)
        return node;
        
        return par[node]=findPar(par[node]);
    }
    
    void unionByRank(int u ,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        
        if(ulp_u == ulp_v) return;
        
        if(rank[ulp_u]>rank[ulp_v]){
            par[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v]){
            par[ulp_u]=ulp_v;
        }
        else{
            par[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
    
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<pair<int ,pair<int,int>>>edges;
       
       for(int i=0; i<V;i++){
         for(auto it : adj[i]){
           edges.push_back({it[1] , {i ,it[0]}});
         }
       }

       sort(edges.begin() ,edges.end());
       DisjointSet ds(V);
       
       int mstWt=0;
       
       for(auto it : edges){
           int wt=it.first;
           int u=it.second.first;
           int v=it.second.second;
           
           if(ds.findPar(u)!=ds.findPar(v)){
               ds.unionByRank(u,v);
               mstWt+=wt;
           }
       }
       return mstWt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends