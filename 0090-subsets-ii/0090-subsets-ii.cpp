class Solution {
public:
    /*
        Approach :
        recurrsive approach :
        TC => O(n)
        SC => O(n)
    */
    void helper(int i, int n , vector<int>& nums  ,vector<int>&subset , vector<vector<int>>& answer)
    {
        // base case
        if(i == n)
        {
            answer.push_back(subset);
            return ;
        }
        // option 1 pick ith element in subset
        subset.push_back(nums[i]);
        helper(i+1 , n, nums , subset ,answer);
        // option 2 don't pick the ith element
        subset.pop_back();
        // remove duplicate subsets
        while(i+1 < n && nums[i] == nums[i+1])i++;
        helper(i+1 , n , nums , subset ,answer);
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin()  , nums.end());
        int n = nums.size();
        vector<int> subset ;
        vector<vector<int>> answer;
        helper(0,n,nums,subset,answer);
        return answer;
    }
};