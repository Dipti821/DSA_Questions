class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        int l = 0, r = row*col - 1;
        while (l != r){
            int mid = (l + r) >> 1;
            if (matrix[mid /col][mid % col] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return matrix[r / col][r % col] == target;
        
        
        // int i=0, j=col-1;
        // while(i<row && j>=0)
        // {
        //     if(matrix[i][j]==target)
        //         return true;
        //     else if(matrix[i][j]>target)
        //         j--;
        //     else
        //         i++;
        // }
        // return false;
    }
};