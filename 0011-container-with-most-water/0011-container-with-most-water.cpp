class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ;
        int left =0, right = n - 1 ;
        int answer =0;
        while(left < right)
        {
            int currentArea = min(height[left],height[right]) * (right-left) ;
            answer = max(answer , currentArea) ;
            if(height[left] < height[right])
            {
                left++ ;
            }
            else
                right--;
        }
        return answer ;
    }
};