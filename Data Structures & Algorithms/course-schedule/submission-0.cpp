class Solution {
public:

    // bool topologicalSort(vector<vector<int>>& prerequisites)//

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        if(n == 0) return true; // no prerequisites

        vector<vector<int>>adjList(numCourses);
        vector<int>indegree(numCourses,0);

        for(int i = 0; i<n; ++i){
            int prereq = prerequisites[i][1];
            int course = prerequisites[i][0];

            adjList[prereq].push_back(course);
            indegree[course]++;
        }


        queue<int>tque;
        
        for(int i = 0; i < numCourses ; ++i){
            if(indegree[i] == 0){
                tque.push(i);
            }
        }

        vector<int>tps;

        while(!tque.empty()){
            int curr = tque.front();
            tque.pop();
            tps.push_back(curr);
            for(int neighbour: adjList[curr]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    tque.push(neighbour);
                }
            }
        }

      

        return tps.size() == numCourses ? true : false;
    }
};
