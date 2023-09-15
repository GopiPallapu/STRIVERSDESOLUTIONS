class Solution {
public: 
    /*
        Approach : 
        TC => O(n*n * 9) => O(n*n)
        SC => O(1)
    */
    bool isValid(vector<vector<char>>& board , int i,int j ,int n , int m  ,char c)
    {
        // row check & col check
        for(int row =0 ; row < m ; row ++)
        {
            if(board[i][row] == c)return false;
            if(board[row][j] == c)return false;
        }
        
        // box check
        int s  =sqrt(n);
        int row = i -i%s;
        int col = j- j%s;
        for(int  rowIndx = row ; rowIndx < row+s;rowIndx++)
        {
            for(int colIndx  =col ; colIndx < col+s;colIndx++)
            {
                if(board[rowIndx][colIndx] == c)return false;
            }
        }
        return true;
    }
    bool help(vector<vector<char>>& board , int i,int j ,int n , int m)
    {
        // step 1 - find empty cell to fill
        for(int row  =i ; row < n ; row++)
        {
            for(int col = j; col < m;col++)
            {
                if(board[row][col] == '.')
                {
                    for(char k = '1'; k<= '9' ;k++)
                    {
                        if(isValid(board , row  ,col , n , m , k ))
                        {
                            board[row][col]  =k;
                            if(help(board , 0 , 0, n , m)) return true;
                            else
                                board[row][col] = '.';

                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        help(board,0,0,n,m);
    }
};