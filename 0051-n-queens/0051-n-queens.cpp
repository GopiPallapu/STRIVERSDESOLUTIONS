class Solution {
public:
    bool isValid(int i , int j , int n ,  vector<vector<char>> &matrix)
    {
        int tempi =i;
        int tempj =j;
        // row check
        for(int k =0;k<n;k++)
        {
            if(matrix[tempi][k] == 'Q') // row check
                return false;
            if(matrix[k][tempj] == 'Q') // col check
                return false;
        }
        tempi = i;
        tempj = j;
        // top left diagonal
        while(tempi >=0 && tempj >=0)
        {
            if(matrix[tempi][tempj] == 'Q')
                return false;
            tempi--;
            tempj--;
        }
        tempi = i;
        tempj = j;
        // top right diagonial
        while(tempi >= 0 && tempj <= n - 1)
        {
            if(matrix[tempi][tempj] == 'Q')
                return false;
            tempi--;
            tempj++;
            
        }
        return true;
    }
    void helper(int i , int n , vector<vector<string>> &ans ,  vector<vector<char>> &matrix)
    {
        if(i == n)
        {
            vector<string> str ;
            for(int j =0 ;j<n;j++)
            {
                string currentRow ="";
                for(int k =0 ;k<n;k++)
                {
                    currentRow.push_back(matrix[j][k]);
                }
                str.push_back(currentRow);
            }
            ans.push_back(str);
            return ;
        }
        for(int j = 0;j<n;j++)
        {
            if(isValid(i,j ,n , matrix))
            {
                matrix[i][j] ='Q';
                helper(i+1 , n,ans,matrix);
                matrix[i][j] ='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> matrix (n , vector<char>(n,'.'));
         vector<vector<string>> ans ;
         helper(0,n,ans , matrix);
         return ans;
    }
};