class Solution {
public:
    int climbStairs(int n) {
        //if(n==1) return 1;
        //vector<int>waysToLevel(n);

        int maxWaysAt1LB = 1, maxWaysAt2LB = 0;
        for(int level = 0; level < n; ++level){
            int maxWaysAtCL = maxWaysAt2LB + maxWaysAt1LB;
            maxWaysAt2LB = maxWaysAt1LB;
            maxWaysAt1LB = maxWaysAtCL;
        }
        return maxWaysAt1LB;
    }

    //TC: O(n), SC: O(n) - bottom up 
};
