class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>triplets;
        sort(nums.begin(), nums.end()); //O(nlogn)

        for(int i = 0; i < n ; ++i){
            if(nums[i] > 0) break; //remaining numbers are positive
            if (i > 0 && nums[i] == nums[i-1]) continue; //skipping duplicate values for the first number as the triplet wull already be present
            int target = 0;
            target -= nums[i];
            int right = n-1;
            int left = i+1;

            while(right >= 0 && left < right){
                if(nums[left] + nums[right] < target){
                    left++;
                } else if(nums[left] + nums[right] > target){
                    right --;
                } else {
                    triplets.push_back({nums[i],nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right and nums[left-1] == nums[left]){
                        left++;
                    }
                }
            }

            
        }

        return triplets;
    }
};
