class Solution {
public:
    int rob(vector<int>& nums) {
        int n =  nums.size();

        //if(n==1) return nums[0];
        //vector<int>moneyRobbed(n,0);


       //logic - you only need the max value at i-1 and i-2
       int maxAtOneBehind = 0, maxAtTwoBehind = 0;
       for(int currHouseMoney: nums){
            int maxMoneyAtCurrHouse = max(currHouseMoney + maxAtTwoBehind, maxAtOneBehind);
            maxAtTwoBehind = maxAtOneBehind; //progression
            maxAtOneBehind = maxMoneyAtCurrHouse;
       }
      
        return maxAtOneBehind; //it's holding the last value of maxmoney at n-1 house
    }

    //TC: O(n), SC: O(1)
};
