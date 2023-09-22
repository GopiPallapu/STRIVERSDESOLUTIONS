class Solution {
public:
/*Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]*/
void helper(int i , int n , int target , vector<int>& set , vector<vector<int>>& answer , vector<int>& candidates ,int  sum)
{
    // base case
    if(sum == target)
    {
        answer.push_back(set);
        return ;
    }
    if(sum > target )return ;
    if(i >= n) return;
    
    sum +=candidates[i] ;
    set.push_back(candidates[i]);
    helper(i+1 , n , target , set , answer , candidates , sum);
    
    sum -= candidates[i] ;
    set.pop_back() ;
    while(i+1 < n && candidates[i] == candidates[i+1])i++ ;
     helper(i+1 , n , target , set , answer , candidates , sum);
     
     return ;
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       int n = candidates.size() ;
       vector<vector<int>> answer ;
       vector<int> set ;
       sort(candidates.begin() , candidates.end()) ;
       helper( 0 , n , target ,set , answer  , candidates , 0);
       return answer;
}

};