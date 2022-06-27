class Solution {
    int dir[5]={0,1,0,-1,0};
public:
    void dfs(int i,int j,int row, int col,vector<vector<char>>& grid){
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j]=='0') return;
        grid[i][j]='0';
        for(int k=0;k<4;k++)
            dfs(i+dir[k],j+dir[k+1],row,col,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        int c=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    c++;
                    dfs(i,j,row,col,grid);
                }
                    
            }
        }
        return c;
    }
};
