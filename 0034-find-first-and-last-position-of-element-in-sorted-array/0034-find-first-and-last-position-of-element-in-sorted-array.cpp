class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = n , last   = n ;
        int left =0 , right = nums.size()-1;
        
        // find lower bound for target
        while(left <= right)
        {
            int mid = (left+right)/2 ;
            if(nums[mid] >= target)
            {
                first = mid;
                right = mid-1;
            }
            else
                left = mid+1 ;
        }
        if(first== n || nums[first] != target)return {-1,-1};        
        // find upper bound
        left =0, right = nums.size()-1;
        while(left <=  right)
        {
            int mid = (left+right)/2 ;
            if(nums[mid] > target)
            {
                last = mid;
                right = mid-1;
            }
            else
                left = mid+1 ;
        }
        return {first , last-1};
    }
};