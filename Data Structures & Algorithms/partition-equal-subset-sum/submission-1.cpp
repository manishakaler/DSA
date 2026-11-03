class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //dp - bottom up

        int n = nums.size();

        int totalSum = 0;

        for(int i = 0; i < n; i++){
            totalSum+= nums[i];
        }

        if(totalSum%2 !=0) return false;

        int target = totalSum/2;

        vector<bool>dp(target+1,false);
        vector<bool>newDp(target+1,false);

        dp[0] = true;
       

        for(int i = 0; i<n; ++i){
            for(int j = 1; j<=target; ++j){
                if(j >= nums[i]){
                    newDp[j] = dp[j] || dp[j - nums[i]];
                }else{
                    newDp[j] = dp[j];
                }
            }

            swap(dp,newDp);
        }

        return dp[target];
    }
};
