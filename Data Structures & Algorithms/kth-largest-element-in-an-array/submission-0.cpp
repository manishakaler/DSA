class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>>minHeap;

        for(int elem: nums){
            minHeap.push(elem);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};
