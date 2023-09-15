class Solution {
public:
    void helper(int index , vector<int>& nums , vector<vector<int>>& answer)
    {
        // base case
        if(index == nums.size())
        {
            answer.push_back(nums);
            return;
        }
        for(int i = index ; i < nums.size(); i++)
        {
            swap(nums[i],nums[index]);
            helper(index+1 , nums , answer);
             swap(nums[i],nums[index]);
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer ;
        helper(0, nums  ,answer);
        return answer;
    }
};