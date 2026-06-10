using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq_map;

        for(int i=0; i < n ; i++){
            if (freq_map[nums[i]]){
                return true;
            }
            freq_map[nums[i]]++;
        }

        return false;
    }
};