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
        helper(i+1, n , target, candidates , ans, subset, sum);//  we are not inc i value because i may be included more times
        // skip ith value
        sum -=candidates[i];
        subset.pop_back();
         while(i+1 < n && candidates[i] == candidates[i+1])i++;
         helper(i+1, n , target, candidates , ans, subset, sum); 

         return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
        vector<int> subset;
        int n = candidates.size();
        sort(candidates.begin() , candidates.end());
        helper(0,n,target,candidates , ans,subset , 0);
        return ans;
    }
};