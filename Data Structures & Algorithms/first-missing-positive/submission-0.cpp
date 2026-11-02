class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool>present(n+1,false);
        // for n distinct +ve numbers, to find a missing number, it can max be n+1 (if all numbers are present continuously)
        for(int i = 0; i < n; ++i){
            if(nums[i]>0 && nums[i] <= n){
                present[nums[i] - 1] = true;
            }
        }

        for(int i = 0; i < n ; ++i){
            if(present[i] == false){
                return i+1;
            }
        }

        return n+1;
       
    }
};