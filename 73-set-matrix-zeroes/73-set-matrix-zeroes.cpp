class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        unordered_map<int,int>r,c;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0)
                {
                    r[i]++;
                    c[j]++;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(r.find(i)!=r.end() || c.find(j)!=c.end())
                    matrix[i][j]=0;
            }
        }
        
    }
};