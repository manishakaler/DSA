class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int res = nums[0];

        int left = 0, right = n-1, mid = (left+right)/2;

        while(right>=left){
            if(nums[left] < nums[right]){
                res = min(res, nums[left]);
                break;
            }
             

            mid = left + (right - left)/2;
            res = min(res, nums[mid]);
            if(nums[left] <= nums[mid]){ 
                //both in left sorted portion- move towards right
                left = mid + 1; 

            }else if (nums[right] >= nums[mid]){
                //both in right segment - move to left
                right = mid - 1;
            }
        }

        return res;
    }
};
