class Solution {
public:
     int getNeighBourOnes(vector<vector<int>>& board , int row,int col,int C,int R){
         int cnt = 0;
        cnt += row - 1 >= 0 && board[row - 1][col] ? 1 : 0;
        cnt += row + 1 < R && board[row + 1][col] ? 1 : 0;
        cnt += col - 1 >= 0 && board[row][col - 1] ? 1 : 0;
        cnt += col + 1 < C && board[row][col + 1] ? 1 : 0;
        cnt += row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1] ? 1 : 0;
        cnt += row - 1 >= 0 && col + 1 < C && board[row - 1][col + 1] ? 1 : 0;
        cnt += row + 1 < R && col - 1 >= 0 && board[row + 1][col - 1] ? 1 : 0;
        cnt += row + 1 < R && col + 1 < C && board[row + 1][col + 1] ? 1 : 0;
        
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
         vector<vector<int>> tempBoard = board;   
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int countofOnes = getNeighBourOnes(tempBoard,i,j,n,m);
                if(board[i][j]==1 ){
                    if(countofOnes <2 || countofOnes >3)
                        board[i][j]=0;
                }
                else if(board[i][j]==0 && countofOnes==3)
                    board[i][j]=1;
            }
        }
    }
};