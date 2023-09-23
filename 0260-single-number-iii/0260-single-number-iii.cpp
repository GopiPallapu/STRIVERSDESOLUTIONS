class Solution {
public:
    bool checkBit(int num , int i)
    {
        if((num & (1 << i)) == 0)
            return false;
        else
            return true;
    }
    vector<int> singleNumber(vector<int>& nums) {
        int answer = 0;
        for(int i = 0 ; i< nums.size() ; i++)
        {
            answer = answer ^ nums[i];
        }
        int index = 0;
        for(int i =0 ; i < 32 ;i++)
        {
            if(checkBit(answer , i))
            {
                index = i ;
            }
        }
        int s1 =0;
        int s2 =0 ;

        for(int i = 0; i< nums.size() ; i++)
        {
            if(checkBit(nums[i] , index) == true)
            {
                s1 = s1 ^ nums[i] ;
            }
            else
            {
                s2 = s2 ^ nums[i] ;
            }
        }
        return {s1 , s2} ;
    }
};