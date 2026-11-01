class Solution {
public:
    int findMin(vector<int> &nums) {
        //you need to find the lowest number so we need to move to the shorter half 
        //aslo check if you are already in a sorted arr

        int left = 0;
        int right = nums.size() - 1;
        int res = 1e9;

        while(left <= right){
            if(nums[left] <= nums[right]){
                res = min(res, nums[left]);
                return res;
            }

            int mid = left + (right - left)/2;

            res=min(res, nums[mid]);

            if(nums[mid] >= nums[left]){ //left is sorted
                left = mid + 1;
            }else { 
                right = mid - 1;
            }
        }

        return res;
    }
};
