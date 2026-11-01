class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int>dp(amount+1,amount+1);

        //why amount + 1 as max cause that is unttainable for this problem
        dp[0] = 0;


        // dp[a] = 1+ min(dp[a-c]);
        for(int i = 0; i <=amount; ++i){
            for(int coin : coins){
                if(i - coin >=0){
                    dp[i] = min(dp[i], 1+ dp[i - coin]);
                }
                
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
