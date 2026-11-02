class Solution {
public:
    int search(vector<int>& nums, int target) {
        //think think - 
        int left = 0;
        int right = nums.size() -1 ;
        int mid;
        while(left <= right){
            mid = left + (right - left)/2;

            if(nums[mid] == target){
                return mid;
            }
            // left sorted array
            if(nums[mid] >= nums[left]){
                if(target > nums[mid] || target < nums[left]){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                //right sorted array
                if(target < nums[mid] || target > nums[right]){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }
};
