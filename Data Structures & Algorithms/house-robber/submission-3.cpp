class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>money(nums.size(),0);
        int n = nums.size();
        if(n==1) return nums[0];

        money[0]=nums[0];
        money[1]=max(nums[0],nums[1]);

        for(int i=2; i<n; ++i){
            money[i]=max(money[i-1], nums[i]+ money[i-2]);
        }
        return money[n-1];
    }
};
