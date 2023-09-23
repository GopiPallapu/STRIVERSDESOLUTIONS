class Solution {
public:
    bool checkBit(int num , int i)
    {
        if((num & (1 << i)) == 0)
            return false;
        else
            return true;
    }
    int singleNumber(vector<int>& nums) {
        int answer = 0;
         //  get count of each bits in the num and take mood 
         // if mod gives 1 then return that num

         for(int i = 0; i < 32 ; i++)
         {
             int count =0;
             for(int j = 0 ; j< nums.size() ; j++)
             {
                 if(checkBit(nums[j] , i) == true)
                 {
                     count ++ ;
                 }
             }
             if(count % 3 == 1)
             {
                 answer = answer + ( 1<<i) ;
             }
         }
         return answer ;
    }
};