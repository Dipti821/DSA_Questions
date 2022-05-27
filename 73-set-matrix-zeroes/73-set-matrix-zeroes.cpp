class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        //Method 1
//         unordered_map<int,int>r,c;
        
//         for(int i=0;i<row;i++){
//             for(int j=0;j<col;j++){
//                 if(matrix[i][j]==0)
//                 {
//                     r[i]++;
//                     c[j]++;
//                 }
//             }
//         }
//         for(int i=0;i<row;i++){
//             for(int j=0;j<col;j++){
//                 if(r.find(i)!=r.end() || c.find(j)!=c.end())
//                     matrix[i][j]=0;
//             }
//         }
        
        // Method 2: using matrix as the indicators
        
         bool isCol=false;
         for(int i=0;i<row;i++){
              if (matrix[i][0] == 0) 
              isCol = true;
      
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0)
                {
                   matrix[i][0]=0;
                   matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                matrix[i][j]=0;
            }
        }
        
        if(matrix[0][0]==0){
            for(int j=0;j<col;j++)
                matrix[0][j]=0;
        }
         if(isCol){
            for(int j=0;j<row;j++)
                matrix[j][0]=0;
        }
        
        
    }
};