class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if(n == 1) return intervals;

        vector<vector<int>>merged;
        sort(intervals.begin(), intervals.end());

        int cstart = intervals[0][0];
        int cend = intervals[0][1];

       
        for(int i = 1 ; i < n ; ++i){
            if(intervals[i][0] <= cend){
                cend = max(intervals[i][1], cend);
            } else{
                merged.push_back({cstart,cend});
                cstart = intervals[i][0];
                cend = intervals[i][1];
            }

        }
        merged.push_back({cstart,cend});
        return merged;

        //time complexity - 
        // m merged intervals 
        // O(n )+ O(m) + O(nlogn)
        //space complexity - O(1) + O(log n) - stack space for sort
    }
};
