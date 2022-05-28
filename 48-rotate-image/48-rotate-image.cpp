class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void reverse(vector<vector<int>>& matrix){
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++)
                swap(matrix[i][j],matrix[i][n-1-j]);
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        // Method 1: TC: O(ROW*COL) SC:O(1)
        int n=matrix.size();
        // for(int i=0;i<(n+1)/2;i++){
        //     for(int j=0;j<n/2;j++){
        //         int temp=matrix[n-1-j][i];
        //         matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
        //         matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
        //         matrix[j][n-1-i]=matrix[i][j];
        //         matrix[i][j]=temp;
        //     }
        // }
        
        // Method 2: transposed plus reversed
        
         transpose(matrix);
         reverse(matrix);
        
    }
};