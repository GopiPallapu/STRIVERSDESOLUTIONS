class Solution {
public:
    /*
        Approach : sort them and fix one number start find next two numbers by using two pointer approach
        TC => O(n log n)
        SC => O(1)
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector < vector < int >> ans;
    sort(nums.begin() , nums.end());
    for(int i=0;i<n;i++){
      if(i>0 && nums[i]==nums[i-1])continue;
      int start = i+1;
      int end=n-1;
      while(start<end){
        int sum = nums[i]+nums[start]+nums[end];
        if(sum==0){
          ans.push_back({nums[i] , nums[start] , nums[end]});
          while(start<end && nums[start]==nums[start+1])start++;
          while(start<end && nums[end]==nums[end-1])end--;
            start++;
          end--;
        }
        else if(sum<0){
          start++;
        }
        else
        {
          end--;
        }
      }

    }
    return ans;
    }
};