class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if (n<=1) return 0;

        int profit = 0;
     

        for(int right = 1 ; right < n ; ++right){
            int sell = prices[right];
            int left = 0;

            while(left < right){
                profit = max(profit, sell - prices[left]);
                left++;
            }

        }

        return profit > 0? profit : 0;

    }
};
