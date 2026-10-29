class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        vector<int>waysToLevel(n);

        waysToLevel[0] = 1;
        waysToLevel[1]=2; // 1 step at a time or two steps

        for(int i = 2; i < n; ++i){
            waysToLevel[i] = waysToLevel[i-1] + waysToLevel[i-2];
        }

        return waysToLevel[n-1];

    }

    //TC: O(n), SC: O(n) - bottom up 
};
