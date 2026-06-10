using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;

        for(int i=0; i < n ; i++){
            if (mp[nums[i]]){
                return true;
            }
            mp[nums[i]]++;
        }

        return false;
    }
};