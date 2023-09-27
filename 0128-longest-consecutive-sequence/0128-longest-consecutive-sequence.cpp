class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map ;
        for(int i =0;i< nums.size();i++)
        {
            map[nums[i]] = i;
        }
        int answer =0;
        for(auto var : map)
        {
            if(map.find(var.first-1) == map.end())
            {
                int x = var.first ;
                int count = 1;
                while(map.find(x+1) != map.end())
                {
                    x ++;
                    count ++;
                }
                answer = max(answer , count);
            }
        }
        return answer ;
    }
};