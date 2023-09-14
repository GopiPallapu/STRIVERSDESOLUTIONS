class Solution {
public:
    /*
        Approach :
        using two pointer approach from left and right
        find max left and max right and check with current left, right and get answer
        TC => O(n)
        SC => O(1)
    */
    int trap(vector<int>& height) 
    {
        int n = height.size();
        int left =0 , right = n-1 ,leftB = height[0] , rightB = height[n-1];
        int answer = 0;
        while(left <= right)
        {
            if(leftB < rightB)
            {
                if(height[left] > leftB)
                {
                    leftB = height[left];
                }
                else
                {
                    answer +=leftB-height[left];
                    left++;
                }
            }
            else
            {
                if(height[right] > rightB)
                {
                    rightB =height[right];
                }
                else
                {
                    answer +=rightB-height[right];
                    right--;
                }
            }
        }
        return answer;
    }
};