class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if (n<=1) return 0;

        int profit = 0;
        int buy_min = prices[0];

        for(int right = 1 ; right < n ; ++right){
            int sell = prices[right];
            int buy_min = min(buy_min,prices[right-1]);

            
            profit = max(profit, sell - buy_min);
               

        }

        return profit > 0? profit : 0;

    }
};
