class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin(),nums.end()) ;
        vector<vector<int>> answer ;
        for(int i =0 ;i< n ; i++)
        {
            int left =i+1 , right = n-1 ;
            if(i != 0 && nums[i] == nums[i-1])
                continue ;
            while(left < right)
            {
                if(nums[i]+nums[left]+nums[right] == 0)
                {
                    answer.push_back({nums[i] , nums[left] , nums[right]}) ;
                    left++;right--;
                    while(left < right && nums[left] == nums[left-1])left++ ;
                    while(right < right && nums[right] == nums[right+1])right-- ;
                }
                else if(nums[i]+nums[left]+nums[right]  < 0)
                    left++ ;
                else
                    right-- ;
            }
        }
        return answer ;
    }
};