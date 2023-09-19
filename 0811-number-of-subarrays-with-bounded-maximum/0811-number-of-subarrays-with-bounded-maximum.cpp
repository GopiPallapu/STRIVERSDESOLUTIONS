class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int j =0;
        int answer =0;
        int previous = 0;
        // iterating array and finding out element with in the range less than range or greater
        // based on that we are adding total range (i-j+1)
        int n = nums.size() ;
        for(int i =0 ;i< n ; i++)
        {
            if(nums[i] >= left && nums[i] <= right)
            {
                answer +=(i-j+1);
                previous = i-j+1;
            }
            else if(nums[i] <= left)
            {
                answer +=previous ;
            }
            else
            {
                j = i+1;
                previous =0;
            }
        }
        return answer;
    }
};