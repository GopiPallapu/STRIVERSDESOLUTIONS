class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX ;
        int maxProfitObtained = INT_MIN ;
        for(int i =0 ; i<prices.size() ; i++)
        {
            minPrice = min(minPrice ,  prices[i]) ;
            maxProfitObtained = max(maxProfitObtained , prices[i]- minPrice) ;
        }
        return maxProfitObtained ;
    }
};