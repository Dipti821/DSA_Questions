// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Prims Algo
        
        // code here
        // vector<int>key(V,INT_MAX);
        // vector<bool>mst(V,false);
        // key[0]=0;
        // for(int count=0;count<V-1;count++)
        // {
        //     int mini=INT_MAX , u;
        //     for(int v=0; v<V;v++)
        //     {
        //         if(mst[v]==false && key[v]<mini)
        //         {
        //             mini=key[v];
        //             u=v;
        //         }
        //     }
        //     mst[u]=true;
        //     for(auto it : adj[u])
        //     {
        //       int k=it[0];
        //       int weight=it[1];
        //       if(mst[k]==false && weight<key[k])
        //       {
        //           key[k]=weight;
        //       }
        //     }
        // }
        // int sum=0;
        // for(int i=0;i<V;i++)
        // {
        //     sum+=key[i];
        // }
        // return sum;
        
        //Kruskal's Algo
        
         vector<int> parent(V), rank(V);
        for(int x = 0; x < V; x++) {
            parent[x] = x;
            rank[x] = 1;
        }
        
        auto find = [&](int node, auto &find) -> int {
            return (parent[node] == node ? node : parent[node] = find(parent[node], find));
        };
        
        auto unite = [&](int node1, int node2) -> void {
            node1 = find(node1, find);
            node2 = find(node2, find);
            if(node1 != node2){
                if(rank[node1] < rank[node2]){
                    swap(node1, node2);
                }
                parent[node2] = node1;
                rank[node1] += rank[node2];
            }
        };
        
        int ans = 0;
        vector<pair<int, pair<int, int>>> vp;
        for(int x = 0; x < V; x++){
            for(auto z: adj[x]){
                vp.push_back({z[1], {x, z[0]}});
            }
        }
        sort(vp.begin(), vp.end());
        for(auto x: vp){
            if(find(x.second.first, find) != find(x.second.second, find)) {
                ans+=x.first;
                unite(x.second.first, x.second.second);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


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