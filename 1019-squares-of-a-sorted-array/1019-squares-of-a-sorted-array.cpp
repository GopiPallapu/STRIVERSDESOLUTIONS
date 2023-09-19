class Solution {
public:
    // using two pointers , fill answer array from right to left
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n , 0);
        int k = n-1;
        int left =0;
        int right = n-1;
        while( left <= right )
        {
            if(nums[left] * nums[left] > nums[right] * nums[right])
            {
                answer[k--] = nums[left] * nums[left];
                left++;
            }
            else
            {
                 answer[k--] = nums[right] * nums[right];
                 right--;
            }
        }
        return answer;
    }
};