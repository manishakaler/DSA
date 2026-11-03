class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int nn = nums.size();

        for(int i = 0; i < nn; i++){
            int val = abs(nums[i]);
            if(nums[val - 1 ] < 0){
                return val;
            }

            nums[val - 1] *= -1;
        }

        return nn;
    }
};
