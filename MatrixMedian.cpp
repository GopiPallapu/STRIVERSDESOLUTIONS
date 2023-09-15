/*
  Approach :
  using binary seach find out search space then count the number of elemnts less than mid if it's less than (n*m)/2 then inc left else dec right
  TC => O( m*(log n))
  SC => O(1)
*/

int getNumbersCountLessThanMid(vector<int>& row , int m)
{
    int left =0;
    int right = row.size()-1;
    while(left <= right)
    {
        int mid = (left+right)/2;
        if(row[mid] <= m)
            left = mid+1;
        else    
            right = mid-1;
    }
    return left;
}
int median(vector<vector<int>> &matrix, int m, int n) {
    int left = 0;
    int right = 0;
    for(int i =0 ;i< m;i++)
    {
        left = min(left , matrix[i][0]);
        right = max(right, matrix[i][n-1]);
    }
    //cout<< left << " "<<right;
    while(left <=  right)
    {
        int mid = (left+right)/2;
        int count =0;
        for(int i =0 ;i < m ; i++)
        {
            count +=getNumbersCountLessThanMid(matrix[i] , mid);
        }
        if(count <= (n*m)/2)
            left = mid+1;
        else   
            right = mid-1;
    }
    return left;
}
