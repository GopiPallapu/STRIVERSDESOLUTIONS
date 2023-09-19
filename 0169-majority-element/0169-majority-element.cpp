class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // using voting algorithm 
        int element =0;
        int count =0;
        int n = nums.size() ;
        for(int i =0 ;i< n;i++)
        {
            if(count == 0)
            {
                element = nums[i];
                count = 1;
            }
            else if(element == nums[i])
                count +=1;
            else
                count -=1;
        }
        return element;
    }
};