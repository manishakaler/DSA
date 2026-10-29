class Solution {
public:
    unordered_map<int,int>cache;
    int recursionForCC(vector<int>& coins, int amount){
        if(amount == 0) return 0;

        if(cache.find(amount) != cache.end()){
            return cache[amount];
        }

        int res = 1e9;
        for(int coin: coins){
            if(amount - coin >=0){
                int output = recursionForCC(coins, amount - coin);
                if(output!= 1e9){
                    res = min(res, 1 + output);
                }
            }
        }
        cache[amount] = res;
        return res;

    }
    int coinChange(vector<int>& coins, int amount) {
        int minCoins = recursionForCC(coins,amount);

        return minCoins >= 1e9 ? -1 : minCoins;

    }
};
