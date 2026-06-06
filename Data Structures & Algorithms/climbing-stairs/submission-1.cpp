class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;

        // vector<int>mem(n+1);
        // mem[1] = 1;
        // mem[2] = 2;

        int first = 1;
        int second = 1;

        for(int i = 2; i<=n; i++){
           int temp = first;
           first = first + second;
           second = temp;
        }

        return first;

        // return mem[n];

    }
};
