class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index =1;
        int n = nums.size();
        int i =0;
        while( index < n)
        {   
                if(nums[index] == nums[i])
                {
                    index++;
                }
                else
                {
                    i++;
                    nums[i] =nums[index];
                    index++;
                }
        }
        return i+1;
    }
};