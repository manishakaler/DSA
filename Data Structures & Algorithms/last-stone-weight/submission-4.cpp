class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n == 1) return stones[n-1];

        //maxHeap
        priority_queue<int>maxHeap;

        for(int i = 0; i <n; ++i){
            maxHeap.push(stones[i]);
        }

        while(maxHeap.size() > 0){
            if(maxHeap.size() == 1) return maxHeap.top();

            int stoneH1 = maxHeap.top();
            maxHeap.pop();
            int stoneH2 = maxHeap.top();
            maxHeap.pop();

            if(stoneH1 == stoneH2){
                continue;
            } else if (stoneH1 > stoneH2){
                maxHeap.push(stoneH1 - stoneH2);
            }

        }

        return 0;
        
    }
};

//TC: O(nlogn)
//SC: O(n) 
