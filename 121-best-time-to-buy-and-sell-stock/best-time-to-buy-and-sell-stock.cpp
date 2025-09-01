class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;
        int pist = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < buy){
                buy = prices[i];
            }
            pist = prices[i] - buy;
            if(profit < pist){
                profit = pist;
            }
        }
        return profit;
    }
};