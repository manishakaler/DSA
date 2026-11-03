class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        int t = tasks.size();

        unordered_map<char, int> freqMap;

        for (int i = 0; i < t; ++i) {
            freqMap[tasks[i]]++;
        }

        priority_queue<int> maxHeap;

        for (auto& entry : freqMap) {
            maxHeap.push(entry.second);
        }

        int time = 0;
        queue<pair<int, int>> freqToNextAvail;
        
        while(!maxHeap.empty() || !freqToNextAvail.empty()){
            time++;
            
            if(maxHeap.empty()){
                time = freqToNextAvail.front().second;
            }else{
                int currFreq = maxHeap.top() - 1;
                maxHeap.pop();
                if(currFreq>0){
                    freqToNextAvail.push({currFreq,time+n});
                }
            }

            if(!freqToNextAvail.empty() && freqToNextAvail.front().second == time){
                maxHeap.push(freqToNextAvail.front().first);
                freqToNextAvail.pop();
            }

        }
       
        return time;
    }
};
