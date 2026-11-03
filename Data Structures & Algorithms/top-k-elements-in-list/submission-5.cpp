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
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minHeap;
        
        //mlog(k+1)
        for(auto& entry: freqMap){
            minHeap.push({entry.second,entry.first});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }


       // O(k)
        while(!minHeap.empty()){
            topK.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return topK;
    }
};
