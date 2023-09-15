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
     int helper(int i , int n ,  vector<vector<char>> &matrix , vector<int>& leftRow , vector<int>& lowerdiagonal , vector<int>& upperdiagonal)
    {
        if(i == n)
        {
           return 1;
        }
        int ans =0;
        for(int j = 0;j<n;j++)
        {
            if(leftRow[j] == 0 && lowerdiagonal[i+j] == 0 && upperdiagonal[(n-1)+(j-i)] == 0)
            {
                matrix[i][j] ='Q';
                leftRow[j] = 1;
                lowerdiagonal[i+j] = 1;
                upperdiagonal[(n-1)+(j-i)] = 1;
                ans += helper(i+1 , n,matrix, leftRow , lowerdiagonal, upperdiagonal);
                matrix[i][j] ='.';
                leftRow[j] = 0;
                lowerdiagonal[i+j] = 0;
                upperdiagonal[(n-1)+(j-i)] = 0;
            }
        }
        return ans ;
    }
    int totalNQueens(int n) {
        vector<vector<char>> matrix (n , vector<char>(n,'.'));
         // using hashing isvalid function is going to be arrased
         vector<int> leftRow (n,0) ,lowerdiagonal(2 * n  - 1 , 0) , upperdiagonal (2 * n - 1 , 0);
         return helper(0,n, matrix , leftRow  ,lowerdiagonal ,upperdiagonal );
    }
};