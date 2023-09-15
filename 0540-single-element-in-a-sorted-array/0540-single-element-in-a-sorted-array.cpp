class Solution {
public:
    // TC => O(log n) SC => O(1)
    // using binary search  we can find out single number
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || nums[0] != nums[1])return nums[0];
        if(nums[n-1] != nums[n-2])return nums[n-1];

        // search space
        int left = 1 ;
        int right = n-2;
        // 
        while( left <= right)
        {
            int mid = (left + right)/2;
            // if we found single number at mid
            if(nums[mid] != nums[mid-1] && nums[mid] !=nums[mid+1])return nums[mid]; 
            else if((mid%2 ==0 && nums[mid] == nums[mid+1])  ||
                     (mid%2 ==1 && nums[mid] == nums[mid-1]))
                left = mid+1;
            else
                right = mid-1;
        }
        return 0;
    }
};