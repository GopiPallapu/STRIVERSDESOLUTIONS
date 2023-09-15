class Solution {
public:
    void helper(int i , int n, int target ,vector<int> &candidates ,vector<vector<int>> &ans, vector<int> &subset )
    {
        // base case
        if(i == n)
        {
            if(target == 0)
            {
                ans.push_back(subset);
            }
            return;
        }
        // take ith value
        if(candidates[i] <= target)
        {
            subset.push_back(candidates[i]);
             //  we are not inc i value because i may be included more times
            helper(i, n , target-candidates[i], candidates , ans, subset);
            // skip ith value
            subset.pop_back();
        }
       
         helper(i+1, n , target, candidates , ans, subset); 

         return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        int n = candidates.size();
        helper(0,n,target,candidates , ans,subset);
        return ans;
    }
};