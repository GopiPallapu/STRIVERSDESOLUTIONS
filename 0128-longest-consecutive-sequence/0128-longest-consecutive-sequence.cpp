class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size() ;
        int answer = 0 ;
        unordered_map<int,int> mp ;
        for(int i =0 ;i< n ; i++)
        {
            mp[nums[i]]++ ;
        }
        for(auto var : mp)
        {
            int num  = var.first ;
            if(mp.find(num-1) == mp.end())
            {
                int count = 1 ;
                int x = num ;
                while(mp.count(x+1) > 0)
                {
                    count ++ ;
                    x = x+1 ;
                }
                answer = max(answer , count) ;
            }
        }
        return answer ;
    }
};