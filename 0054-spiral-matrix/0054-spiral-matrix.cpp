class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        int left =0 , right =m-1 , top = 0 , bottom = n-1 ;
        vector<int> answer ;
        while(left <= right && top <= bottom)
        {
            // left to right
            for(int i = left ; i <= right ; i++)
            {
                answer.push_back(matrix[top][i]) ;
            }
            top++ ;
            // top to bottom
            for(int i = top ; i<= bottom ; i++)
            {
                answer.push_back(matrix[i][right]) ;
            }
            right-- ;
            // right to left
            if(top <= bottom )
            {
                 for(int i = right ; i >= left ; i--)
                {
                     answer.push_back(matrix[bottom][i]) ;
                }
                bottom-- ;
            }
           
            // from bottom to top
            if(left <= right)
            {
                for(int i = bottom ; i >= top ; i--)
                {
                    answer.push_back(matrix[i][left]) ;
                }
                left++ ;
            }
        }
        return answer ;
    }
};