class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ;
        int left  =0;
        int right = n-1;
        int answer  =0;
        while(left <= right)
        {
            int minH = min(height[left] , height[right]);
            int maxW = right - left ;
            answer = max(answer , minH*maxW);

            if(height[left] < height[right])
                left +=1;
            else
                right -=1;
        }
        return answer;
    }
};