class Solution {
public:
    int rob(vector<int>& nums) {
        int n =  nums.size();

        if(n==1) return nums[0];
        vector<int>moneyRobbed(n,0);
        moneyRobbed[0] = nums[0];
        moneyRobbed[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < n; ++i){
            moneyRobbed[i]= max(nums[i]+moneyRobbed[i-2], moneyRobbed[i-1]);
        }

        return moneyRobbed[n-1];
      
    }
};
