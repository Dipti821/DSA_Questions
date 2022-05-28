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
        
        
        /*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
// void rotate(vector<vector<int> > &matrix) {
//     reverse(matrix.begin(), matrix.end());
//     for (int i = 0; i < matrix.size(); ++i) {
//         for (int j = i + 1; j < matrix[i].size(); ++j)
//             swap(matrix[i][j], matrix[j][i]);
//     }
// }

/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
// void anti_rotate(vector<vector<int> > &matrix) {
//     for (auto vi : matrix) reverse(vi.begin(), vi.end());
//     for (int i = 0; i < matrix.size(); ++i) {
//         for (int j = i + 1; j < matrix[i].size(); ++j)
//             swap(matrix[i][j], matrix[j][i]);
//     }
// }
        
    }
};