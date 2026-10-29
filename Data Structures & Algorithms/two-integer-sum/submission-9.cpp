class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>tgtIdxMap;

        for(int i = 0; i <n ; ++i){
            if(tgtIdxMap.find(target-nums[i]) != tgtIdxMap.end() && tgtIdxMap[target-nums[i]] != i){

                return {tgtIdxMap[target-nums[i]], i};
            }else {
                tgtIdxMap[nums[i]] = i;
            }
            
        }

        return {-1,-1};
    }
};
