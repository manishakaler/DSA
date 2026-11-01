class Solution {
public:
    int search(vector<int>& nums, int target) {
        //note the ascending and we need to find something so binary search ding ding ding

        //questions - type of entrues in array - integers
        //length of the array - [1,10000]
        // value of nums - [-10000,10000]
        // are there duplicates? - no 

        int n = nums.size();
        int left = 0;
        int right = n -1;
        int mid;

        while(left <= right){
            mid = left + (right - left)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] > target){
                right = mid - 1;
            }

            if(nums[mid] < target){
                left = mid + 1;
            }
        }

        return -1;
        
    }
};
