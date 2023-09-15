class Solution {
public:
    void helper(int i , int n, int target ,vector<int> &candidates ,vector<vector<int>> &ans, vector<int> &subset , int sum)
    {
        if(sum == target)
        {
            ans.push_back(subset);
            return;
        }
        if(sum > target)return ;
        if( i >= n)return ;
        // take ith value
        sum += candidates[i];
        subset.push_back(candidates[i]);
        //  we are not inc i value because i may be included more times
        helper(i, n , target, candidates , ans, subset, sum);
        // skip ith value
        sum -=candidates[i];
        subset.pop_back();
         helper(i+1, n , target, candidates , ans, subset, sum); 

         return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        int n = candidates.size();
        helper(0,n,target,candidates , ans,subset , 0);
        return ans;
    }
};