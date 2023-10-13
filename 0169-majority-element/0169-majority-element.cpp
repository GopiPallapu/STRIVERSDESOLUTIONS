class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count  =0 ;
        int value  =0;
        for(int i =0 ;i< nums.size() ; i++)
        {
            if(count  == 0)
            {
                value = nums[i] ;
            }
            if(value == nums[i])
            {
                count ++ ;
            }
            else
            {
                count -- ;
            }
        }
        return value ;
    }
};