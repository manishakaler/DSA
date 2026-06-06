class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int left = 0, right = n-1;

        while(left <= right){
            int mid = left + (right - left)/2 ;

            if(nums[mid] == target){
                return mid;
            }

            // left sorted portion
            if(nums[mid] >= nums[left]){
              
                if(target < nums[left] || target > nums[mid]){
                    left = mid + 1;
                }else {
                    right = mid - 1;
                }

            } else {
               //right sorted portion
                if(target < nums[mid] || target > nums[right]){
                    right = mid - 1;
                }else {
                    left = mid + 1;
                }

            }
        }

        return -1;
    }

    // int binarySearch(vector<int>& nums, int left, int right, int target){
   
    //     while(left <= right){
    //         int mid = left + (right - left)/2;

    //         if(nums[mid] == target){
    //             return mid;
    //         }else if (nums[mid] < target){
    //             left = mid + 1;
    //         }else {
    //             right = mid-1;
    //         }
    //     }

    //     return -1;
    // }
};
