class Solution {
public:
    int  getDays(int size , vector<int>& weights)
    {
            int days =1;
            int load = 0;
            int n =weights.size() ;
            for(int i =0; i< n ; i++)
            {
                if(load + weights[i] > size)
                {
                    days +=1;
                    load = weights[i];
                }
                else
                {
                    load += weights[i];
                }
            }
            return days ;
    }
    int shipWithinDays(vector<int>& weights, int days) {
       /* approach :
          using binary search on answers
          find the space for which answer may exists
          TC => O(N * (log)(sumof W - max of W))
          SC => O(1)
       */
       int left = *max_element(weights.begin()  , weights.end()) ;
       int right = accumulate(weights.begin() , weights.end() , 0);

       while(left <= right)
       {
           int mid = (left+right)/2 ;
           int d = getDays(mid , weights ) ;
           if(d <= days)
           {
               right = mid - 1 ;
           }
           else
           {
               left = mid + 1 ;
           }
       }
       return left ;
    }
};