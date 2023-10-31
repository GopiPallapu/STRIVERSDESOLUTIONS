class Solution {
public:
    /*
        Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
        Output: 6
    */
    int trap(vector<int>& height) {
        int n = height.size() ;
        int waterDepth =0 ;
        int left =0 , right = n-1 , leftBar = height[left] , rightBar = height[right] ;
        while(left < right)
        {
            if(leftBar < rightBar)
            {
                if(leftBar < height[left])
                {
                    leftBar = height[left] ;
                    continue ;
                }
                else
                {
                    waterDepth += leftBar- height[left] ;
                    left ++ ;
                }
            }
            else
            {
                if(rightBar < height[right])
                {
                    rightBar = height[right] ;
                    continue ;
                }
                else
                {
                    waterDepth += rightBar- height[right] ;
                    right -- ;
                }
            }
        }
        return waterDepth ;
    }
};