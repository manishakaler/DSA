class Solution {
   public:
    bool backtrackForSum(vector<int>& nums, int target, int currSum, int idx) {
        if (idx >= nums.size()) {
            return false;
        }
        if (currSum == target) {
            return true;
        }

        return backtrackForSum(nums, target, currSum + nums[idx], idx + 1) ||
               backtrackForSum(nums, target, currSum, idx + 1);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        if (totalSum % 2 != 0) return false;

        return backtrackForSum(nums, totalSum / 2, 0, 0);
    }
};
