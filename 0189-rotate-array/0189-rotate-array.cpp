class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // rotate whole array - 7,6,5,4,3,2,1
        // rotate first k elements - 5,6,7,4,3,2,1
        // rotate last n-k elements - 5,6,7,1,2,3,4
        int n = nums.size();
        k = k % n;
        reverse(nums.begin() , nums.end());
        reverse(nums.begin() , nums.begin()+k);
        reverse(nums.begin()+ k , nums.end());
    }
};