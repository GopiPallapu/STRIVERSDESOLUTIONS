class Solution {
public:
    // 3,1,2,4
    vector<int> sortArrayByParity(vector<int>& nums) {
       int i =0 , j = nums.size()-1;
       while(i < j)
       {
           while(i < j && nums[i]%2 == 0)
           {
               i++;
           }
           while(i < j && nums[j]%2 == 1)
           {
               j--;
           }
            swap(nums[i],nums[j]);
       }
       return nums;
    }
};