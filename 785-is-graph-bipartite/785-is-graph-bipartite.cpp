class Solution {
public:
    bool bipartitebfs(int src,vector<vector<int>>& graph,vector<int>&color){
        queue<int>q;
        q.push(src);
        color[src]=1;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it: graph[node]){
                if(color[it]==-1){
                    color[it]=1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]) return false;
                
            }
        }
        return true;
    }
    bool bipartitedfs(int src,vector<vector<int>>& graph,vector<int>&color){
        if(color[src]==-1)
            color[src]=1;
        
        for(auto it: graph[src]){
            if(color[it]==-1){
                color[it]=1-color[src];
                if(!bipartitedfs(it,graph,color)) return false;
            }
            else if(color[it]==color[src]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int sz=graph.size();
        
        vector<int>color(sz,-1);
       
        for(int i=0;i<sz;i++){
            if(color[i]==-1)
            {
                if(!bipartitedfs(i,graph,color))
                   return false; 
            }
        }
        return true;
    }
};