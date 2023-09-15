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
    void helper(int i , int n , vector<vector<string>> &ans ,  vector<vector<char>> &matrix , vector<int>& leftRow , vector<int>& lowerdiagonal , vector<int>& upperdiagonal)
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
            if(leftRow[j] == 0 && lowerdiagonal[i+j] == 0 && upperdiagonal[(n-1)+(j-i)] == 0)
            {
                matrix[i][j] ='Q';
                leftRow[j] = 1;
                lowerdiagonal[i+j] = 1;
                upperdiagonal[(n-1)+(j-i)] = 1;
                helper(i+1 , n,ans,matrix, leftRow , lowerdiagonal, upperdiagonal);
                matrix[i][j] ='.';
                leftRow[j] = 0;
                lowerdiagonal[i+j] = 0;
                upperdiagonal[(n-1)+(j-i)] = 0;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> matrix (n , vector<char>(n,'.'));
         vector<vector<string>> ans ;
         // using hashing isvalid function is going to be arrased
         vector<int> leftRow (n,0) ,lowerdiagonal(2 * n  - 1 , 0) , upperdiagonal (2 * n - 1 , 0);
         helper(0,n,ans , matrix , leftRow  ,lowerdiagonal ,upperdiagonal );
         return ans;
    }
};