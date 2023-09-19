class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // this can be done in 2 ways
        // 1. bit manipulation
        // 2. binary search
        /*int x1 =0;
        int x2 =0;
        int maxNum = *max_element(nums.begin() , nums.end()) ;
        for(int i = 1 ; i<= maxNum ; i++)
        {
            x1 = x1 ^ i;
        }
        for(int i =0 ;i < nums.size() ; i++)
        {
            x2 = x2 ^ nums[i];
        }
        return x1 ^ x2;*/
        int left = 1;
        int right = nums.size()-1 ;
        while(left <= right)
        {
            int mid  =(left+right)/2;
            int count =0;
            for(auto i : nums)
            {
                if(i <= mid )count +=1;
            }
            if(count <= mid)
                left = mid +1 ;
            else
                right = mid-1;
        }
        return left;
    }
};