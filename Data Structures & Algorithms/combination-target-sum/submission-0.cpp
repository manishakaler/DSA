class Solution {
public:

    void backtrackForCombnSum(vector<int>& nums, vector<int>& current ,int idx, int target, int sum, vector<vector<int>>& combinations){
        if(target == sum){
            combinations.push_back(current);
            return;
        }

        for(int i = idx; i < nums.size(); ++i){
            if(sum+nums[i] >target){
                continue;
            }
            current.push_back(nums[i]);
                
            backtrackForCombnSum(nums, current, i, target, sum+nums[i], combinations);
            
            
            current.pop_back();
           
        }

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>combinations;
        vector<int>current;
        
        backtrackForCombnSum(nums, current,0, target, 0, combinations);


        return combinations;

    }
};
