class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp ;
        mp[0]= 1 ; // 1,1,1
        int answer =0 , sum =0;
        for(int i =0 ;i< nums.size() ; i++)
        {
            sum += nums[i] ;
            int target = sum - k ;
            if(mp.find(target) != mp.end())
            {
                answer += mp[target] ;
            }
            mp[sum]++;
        }
        return answer ;
    }
};