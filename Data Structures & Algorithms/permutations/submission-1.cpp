class Solution {
public:
    void backtrackForPermute(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& results){
        if(current.size() == nums.size()){
            results.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(used[i]) continue;

            current.push_back(nums[i]);
            used[i] = true;
            backtrackForPermute(nums, current, used, results);

            current.pop_back();
            used[i] = false;
            //not calling backtrack again as skipping is not an option
        }


    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int>currentArr;
        vector<bool>used(nums.size(), false);
        backtrackForPermute(nums, currentArr, used, permutations);

        return permutations;

        //time complexity : recursion - O(n)*no of times recursion is called - n! - O(n*n!)
        //space complexity: O(n) for used + O(n) for current + O(n) auxillary + n!*O(n) for permutations = O(n*n!)
    }
};
