class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 1 jump or two jumps - pick the one with min cost

        //int minCost1LB = 0, minCost2LB = 0;

        for(int i = cost.size() - 3; i >=0; i--){
            cost[i] +=min(cost[i+1], cost[i+2]);
        }

        return min(cost[0], cost[1]);
    }
};
