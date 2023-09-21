class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size() ;
        int index =0 ;
        while(index+1 < n && nums[index] < nums[index+1])
        {
            index++;
        }
        if(index == n-1) // already sorted
        return 0;
        index++ ;
        int current = index ;
        while(index+1 < n && nums[index] < nums[index+1])
        {
            index++;
        }
        if(index != n-1)
            return -1;
        if(nums[current] < nums[0] && nums[n-1] < nums[0])
            return n-current ;
        else
            return -1;
    }
};