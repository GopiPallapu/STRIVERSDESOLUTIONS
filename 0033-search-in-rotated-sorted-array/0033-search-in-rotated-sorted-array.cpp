class Solution {
public:
    // using Binary search we can perform in search space
    // TC => O(log n)
    // SC => O(1)
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0 ;
        int right = n-1;
        while(left <= right)
        {
            int mid = (left+right)/2;
            // correct case if found return index 
            if(nums[mid] == target)return mid;
            // special case if array contain duplicates and matches especially left, mid,right index simply inc those pointers and continue;
            if(nums[left] == nums[mid] && nums[mid] == nums[right])
            {
                left +=1;
                right -=1;
                continue;
            }
            // left part is sorted
            else if(nums[left] <= nums[mid])
            {
                if(nums[left] <= target && target <= nums[mid])
                {
                    right = mid-1;
                }
                else
                    left  = mid +1;
            }
            // right part is sorted
            else
            {
                if(nums[mid] <= target && target <= nums[right])
                {
                    left = mid +1;
                }
                else
                    right = mid -1;
            }
        }
        return -1;
    }
};