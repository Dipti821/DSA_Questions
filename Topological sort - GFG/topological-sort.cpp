// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    	stack<int>s;
	public:
	//Function to return list containing vertices in Topological order.

	void toposortdfs(int node,vector<int> adj[],vector<int> &vis){
	    vis[node]=1;
	    for(auto it: adj[node])
	    {
	        if(!vis[it])
	        toposortdfs(it,adj,vis);
	    }
	   s.push(node); 
	}
	void toposortbfs(int node,vector<int> adj[],vector<int> &vis,int n,vector<int> &ans){
	    vector<int>indegree(n,0);
	    queue<int>q;
	    
	    for(int i=0;i<n;i++){
	        for(auto it: adj[i])
	        indegree[it]++;
	    }
	    
	    for(int i=0;i<n;i++)
	    if(indegree[i]==0) q.push(i);
	    
	    while(!q.empty()){
	        int x=q.front();
	        q.pop();
	        ans.push_back(x);
	        
	        for(auto it: adj[x]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;
	    vector<int>vis(V,0);
	   // for(int i=0;i<V;i++){
	   //     if(!vis[i])
	       //  toposortdfs(i,adj,vis);
	       toposortbfs(0,adj,vis,V,ans);
	   // }
	   //while(!s.empty())
	   //{
	   //    ans.push_back(s.top());
	   //    s.pop();
	   //}
	   return ans; 
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends