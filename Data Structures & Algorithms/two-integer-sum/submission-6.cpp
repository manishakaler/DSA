class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int idxA, idxB = 0;
        map<int,int>elemIdxMap;
        int n = nums.size();

        // for (int i = 0; i < n; ++i){
        //     elemIdxMap[nums[i]]= i;
        //     int diff = target - nums[i];

        //     if(elemIdxMap.count(diff) && elemIdxMap[diff] != i ){
        //         return {elemIdxMap[target - nums[i]], i};
        //     }
            
        // }
      
        // return {0,0};
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (indices.count(diff) && indices[diff] != i) {
                return {i, indices[diff]};
            }
        }

        return {};
    }
};
