class Solution {
public:
    bool isLive(vector<vector<int>>& board , int i , int j){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
            return false;
        if(board[i][j]>=1)
            return true;
        
            return false;
    }
    int countlive(vector<vector<int>>& board , int x , int y){
        int count=0;
        for(int i=x-1;i<x+2;i++){
            for(int j=y-1;j<y+2;j++){
               if(!(i==x && j==y) && isLive(board , i , j))
                   count++;
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
      int row=board.size();
      int col=board[0].size();
        
      for(int i=0;i<row;i++){
          for(int j=0;j<col;j++){
             int num=countlive(board , i ,j);
              
              if(board[i][j]>=1){
                  if(num<2 || num>3)
                      board[i][j]=2;
              }
              else{
                  if(num==3)
                      board[i][j]=-1;
              }
          }
      }
         for(int i=0;i<row;i++){
          for(int j=0;j<col;j++){
              
              if(board[i][j]==2)
                      board[i][j]=0;
               else if(board[i][j] == -1)
                      board[i][j]=1;
              }
              }
          
    }
};