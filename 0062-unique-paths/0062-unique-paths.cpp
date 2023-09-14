class Solution {
public:
    int help(int i , int j , int m , int n , vector<vector<int>>& dp)
    {
        // base case
        if(i == m-1 && j == n-1)return 1;
        if(i >= m || j >= n)return 0;
        if(dp[i][j] !=0)return dp[i][j];
        // option 1 
        int op1 = help(i+1, j, m , n,dp);
        // option 2
        int op2 = help(i , j+1,m ,n,dp);
        dp[i][j] = op1+op2;
        return op1+op2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n,0));
        return help(0 ,0,m, n,dp);
    }
};