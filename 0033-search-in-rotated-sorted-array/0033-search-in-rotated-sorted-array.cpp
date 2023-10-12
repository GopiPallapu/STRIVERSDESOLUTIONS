
/* Input   : nums = [4,5,6,7,0,1,2], target = 0
   Output  : 4
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() ;
        int left =0, right = n-1 ;
        while(left <= right)
        {
            int mid = (right+left)/2 ;
            if(nums[mid] == target)
            {
                return mid ;
            }
            // edge case
            if(nums[left] == nums[mid] && nums[mid] == nums[right])
            {
                left++;
                right--;
                continue ;
            }
            // left part sorted
            if(nums[left] <= nums[mid])
            {
                // target is in left part
                if(nums[left] <= target && target < nums[mid])
                {
                    right = mid-1 ;
                }
                else
                {
                    left = mid +1 ;
                }
            }
            else
            {
                if(nums[mid] < target && target <= nums[right])
                {
                    left = mid +1 ;
                }
                else
                    right = mid-1;
            }
        }
        return -1 ;
    }
};