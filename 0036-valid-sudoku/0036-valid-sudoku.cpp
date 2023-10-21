class Solution {
public:
    bool check(vector<vector<char>>& board , pair<int,int> p1)
    {
        int row = p1.first ,col = p1.second ;
        //row check & col check
        for(int i = 0 ; i < board.size() ; i++)
        {
            if(board[row][col] == board[row][i] && i != col)
                return false;
            if(board[row][col] == board[i][col] && i != row)
                return false;
        }
        int s = sqrt(board.size()) ;
        int startRow = row- row%s ; //1-1%3 = 1-1 = 0
        int startCol = col - col%s ;
        //box check
        for(int i = startRow ; i< startRow+s ;i++)
        {
            for(int j = startCol ; j < startCol+s ; j++)
            {
                if(row != i && col != j && board[row][col] == board[i][j])
                    return false;
            }
        }
        return true ;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>> indices ;
        for(int i =0 ; i< board.size() ; i++)
        {
            for(int j =0 ; j < board[i].size() ; j++)
            {
                if(board[i][j] !='.')
                {
                    indices.push_back({i,j}) ;
                }
            }
        }
        for(int i =0 ; i < indices.size() ; i++)
        {
            if(check(board , indices[i]) == false)
            {
                return false;
            }
        }
        return true ;
    }
};