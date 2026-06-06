class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        seen.insert(nums.begin(), nums.end());
        return seen.size() < nums.size();
    }
};
