class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;

        int n = nums.size();

        if(n==0 || n==1) return false;
        int i = 0;
        while(i<n){
            cout<<freq[nums[i]]<<endl;
            if(freq.find(nums[i]) != freq.end() && freq[nums[i]] >=1){
                return true;
            }

            freq[nums[i]]++;
            i++;
        }

        return false;
    }
};
