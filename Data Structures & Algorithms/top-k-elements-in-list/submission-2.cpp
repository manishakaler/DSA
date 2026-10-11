class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //count freq and store it then somehow sort values in desceding order
        int n = nums.size();
        unordered_map<int,int>freqMap;

        for(int i : nums){
            freqMap[i]++;
        }

        vector<pair<int,int>>freqPairArray(freqMap.begin(), freqMap.end());

        sort(freqPairArray.begin(),freqPairArray.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        vector<int>resp;

        for( auto v = freqPairArray.begin(); v!=freqPairArray.end() && k>0 ; ++v ){
            resp.push_back(v->first);
            k--;
        }

        return resp;
    }
};
