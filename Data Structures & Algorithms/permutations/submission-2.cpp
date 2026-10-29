// array of unique int = possible permutations in any order
//  constraints: arr len – [1,6] & arr entries – [-10,10]

using namespace std;
class Solution {
   public:
    void backtrackForPermute(vector<int>& nums, vector<int>& current, vector<bool>& used,vector<vector<int>>& permutations) {
        if (current.size() == nums.size()) {
            permutations.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            current.push_back(nums[i]);
            backtrackForPermute(nums, current, used, permutations);

            current.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> current;
        vector<bool> used(n, false);
        vector<vector<int>> permutations;
        backtrackForPermute(nums, current, used, permutations);
        return permutations;
    }
    // time complexity : O(n!*n) – O(n) for recursion and O(n!) is the no of times it was called
    // space complexity : O(n*n!) for output – n! no of permutations, each with n entries and O(n!)
    // for recursion stack making it O(n!*n)
};
