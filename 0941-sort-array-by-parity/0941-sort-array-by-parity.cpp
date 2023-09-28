class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result ;
        for(auto i : nums)
        {
            if(i%2 == 0)
            {
                result.push_back(i);
            }
        }

        for(auto i : nums)
        {
            if(i%2 != 0)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};