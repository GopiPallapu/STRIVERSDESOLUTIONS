class Solution {
public:
    bool isValid(vector<vector<char>>& board , int i,int j ,int n , int m )
    {
         
        // row check & col check
        for(int row  =0;row < n;row++)
        {
            if(i!=row &&board[row][j]!='.' &&  board[i][j] == board[row][j])
            {
                cout<<i << " "<<j;return false;
            }
            if(j!=row  &&board[i][row]!='.' && board[i][j] == board[i][row])  {
                cout<<i << " "<<j;return false;
            }
        }
        
        // box check
        int s  =sqrt(n);
        int row = i -i%s;
        int col = j- j%s;
        for(int  rowIndx = row ; rowIndx < row+s;rowIndx++)
        {
            for(int colIndx  =col ; colIndx < col+s;colIndx++)
            {
               if(rowIndx != i && colIndx !=j &&board[rowIndx][colIndx]!='.' && board[i][j] == board[rowIndx][colIndx])
                 {
                        cout<<i << " "<<j;return false;
                }
            }
        }
        return true;
    }
    vector<pair<int,int>> GetNonEmptyIndex(vector<vector<char>>& board , int i ,int j ,int n){
        vector<pair<int,int>> pairs;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(board[i][j]!='.'){
                    pairs.push_back({i,j});
                }
            }
        }
        return pairs;
    }
     bool help(vector<vector<char>>& board , int i,int j ,int n , int m)
    {
        //base
        vector<pair<int,int>> indexs;
        indexs = GetNonEmptyIndex(board , i ,j , n);
        if(indexs.size()>0){
            for(pair<int,int> pair:indexs){
                int row=pair.first;
                int col = pair.second;
                 if(!isValid(board , row  ,col , n , m  ))
                {
                    return false;
                }
            }
        }
       return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        return help(board,0,0,n,m);
    }
};