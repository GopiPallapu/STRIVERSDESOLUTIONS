class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        // max = 9 
         // n = 4
         // dis = 

         int n = nums.size() ;
         int mid = n/2 ;
         int i = mid-1 ;
         int j = n-1 ;
         int answer  =n;
         while(i >= 0)
         {
             if(nums[i] < nums[j])
             {
                 answer -=2 ;
                 j--;
             }
             i--;
         }
         return answer ;
    }
};