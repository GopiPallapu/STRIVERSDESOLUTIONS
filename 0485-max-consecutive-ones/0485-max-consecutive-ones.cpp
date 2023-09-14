class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount =0;
        int count =0;
        for(int i =0 ;i< nums.size() ; i++)
        {
            if(nums[i] == 0)
            {
                maxCount = max(maxCount ,count);
                count =0;
            }
            else
                count +=1;
        }
        maxCount = max(maxCount ,count);
        return maxCount;
    }
};