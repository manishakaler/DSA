class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> resp;

        map<int,int> freqMap;

        for(int x: nums){
            freqMap[x]++;
        }

        auto comp = [](pair<int,int>a, pair<int,int>b){
            return a.second > b.second;
        };

        vector<pair<int,int>> vp;

        for(auto& entry : freqMap){
            vp.push_back({entry.second, entry.first});
            cout<< entry.second <<" "<< entry.first<<" " <<endl;
        }

        sort(vp.begin(), vp.end());

        for(int i = 0, j = vp.size()-1 ; i < k && j >= 0; i++, j--){
            resp.push_back(vp[j].second);
        }
        return resp;
    }
};
