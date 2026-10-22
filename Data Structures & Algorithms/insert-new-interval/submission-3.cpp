class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        int nstart = newInterval[0];
        int nend = newInterval[1];
        bool inserted = false;
        vector<vector<int>>output;
        int i = 0;

        while(i < n && intervals[i][1] < nstart ){
            output.push_back(intervals[i]);
            ++i;
        }

        while(i < n && intervals[i][0] <= nend){
            nend =max(nend, intervals[i][1]);
            nstart = min(nstart, intervals[i][0]);
            ++i;
        }

        output.push_back({nstart,nend});
       
        while(i < n){
            output.push_back(intervals[i]);
            i++;
        }
        

        return output;
    }
};
