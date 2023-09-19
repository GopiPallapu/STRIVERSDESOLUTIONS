class Solution {
public:
    // using kadans algorithm
    int maxSubArray(vector<int>& nums) {
        int answer  = INT_MIN;
        int sum =0;
        int n =nums.size() ;
        for( int i =0; i< n;i++)
        {
            sum +=nums[i];
            answer = max(answer , sum);
            if(sum < 0)
            {
                sum  = 0;
            }
        }
        return answer;
    }
};