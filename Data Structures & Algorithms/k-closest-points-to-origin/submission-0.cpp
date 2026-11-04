class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<double,int>>maxHeap;

        for(int i = 0; i<n; ++i){
            int x = abs(points[i][0]);
            int y = abs(points[i][1]);
            double distance = sqrt((double)(x*x)+ (double)(y*y));

            maxHeap.push({distance,i});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }

        vector<vector<int>>res;
        while(!maxHeap.empty()){
            pair<double,int> entry = maxHeap.top();
            maxHeap.pop();
            res.push_back(points[entry.second]);
        }

        return res;
    }
};
