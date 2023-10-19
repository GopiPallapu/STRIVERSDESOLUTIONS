class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfitObtained = 0 ;
        int i =0 , j =1 ;
        while( j < prices.size())
        {
            if(prices[i] < prices[j])
            {
                maxProfitObtained += prices[j]- prices[i] ;
            }
            i++;j++;
        }
        return maxProfitObtained ;
    }
};