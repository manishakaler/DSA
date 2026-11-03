class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //minHeap

        vector<int>topK;

        int n = nums.size(); 
        unordered_map<int,int>freqMap;
        
        for(int i=0; i<n; ++i){
            freqMap[nums[i]]++; //m distinct
        }
        
        //bucket sort
        vector<vector<int>>freqToVals(n+1);

        for(const auto& entry: freqMap){
            freqToVals[entry.second].push_back(entry.first);
        }
        int count = 0;
        for(int j = n; j >=0; --j){
            if(count == k) break;
            if(freqToVals[j].size() == 0) continue;
            for(auto val: freqToVals[j]){
                if(count >=k) break;
                topK.push_back(val);
                count++;
            }
        }
        return topK;
    }
};
