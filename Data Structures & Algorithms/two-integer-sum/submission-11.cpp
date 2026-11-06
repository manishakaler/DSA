class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int,int>valToIdxMap;

        for(int i = 0; i < n ; ++i){
            int complementary = target - nums[i];
            if(valToIdxMap.find(complementary) != valToIdxMap.end()){
                return {valToIdxMap[complementary], i};
            } 
            valToIdxMap[nums[i]] = i;
        }

        return {-1,-1};
    }
};
