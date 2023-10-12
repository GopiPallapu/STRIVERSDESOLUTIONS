class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR =0 ;
        for(auto x : nums)
        {
            XOR = XOR ^ x ;
        }
        return XOR ;
    }
};