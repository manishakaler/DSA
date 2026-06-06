class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;

        if(stones.size() == 0) return 0;

        for(int i = 0; i<stones.size(); i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
            int mostHeavyStone = pq.top();
            pq.pop();
            int secondMostHeavyStone = pq.top();
            pq.pop();

            int diff = abs(mostHeavyStone - secondMostHeavyStone);
   
            if(diff != 0){
                pq.push(diff);
            }
        }

        return pq.size() == 0 ? 0: pq.top();
    }
};
