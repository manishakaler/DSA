class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort by start values and combine if start of next < end of first

        vector<vector<int>>resp;
        int n = intervals.size();

        if(n==1) return intervals;

        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
            return a[0] < b[0];
        });
        resp.push_back(intervals[0]);
        int rIdx = 0;
        for(int i = 1; i < n && rIdx < resp.size(); ++i){
            if(intervals[i][0] <= resp[rIdx][1]){
                resp[rIdx][1] = max(resp[rIdx][1],intervals[i][1]);
            } else {
                resp.push_back(intervals[i]);
                rIdx++;
            }
        }

        return resp;
        
    }
};
