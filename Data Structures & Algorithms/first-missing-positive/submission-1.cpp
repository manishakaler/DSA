class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // brute force - check for all values starting from 1 - O (N^2)
        // second - sort - O(nlogn) time and O(n) auxiliary space

        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0) {
                nums[i] = 0;
            }
        }

        for (int i = 0; i < n; ++i) {
            int val = abs(nums[i]);
            if (val >= 1 && val <= n) {
                if (nums[val-1]>0) {
                    nums[val - 1] *= -1;
                } else if (nums[val - 1] == 0) {
                    nums[val - 1] = -1 * (n + 1);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 0) {
                return i+1;
            }
        }
        return n + 1;
    }
};