class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //indegree woth queue and then topological

        int np = prerequisites.size();

        if(np == 0) return true;

        vector<vector<int>>adjList(numCourses);
        vector<int>indegree(numCourses,0);

        for(int i = 0; i < np; ++i){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int>availCourses;

        for(int j = 0; j<numCourses ; ++j){
            if(indegree[j]==0){
                availCourses.push(j);
            }
        }
        int coursesTaken = 0;
        while(!availCourses.empty()){
            int currCourse = availCourses.front();
            availCourses.pop();
            coursesTaken++;
            for(int neighbour: adjList[currCourse]){
               indegree[neighbour]--;
               if(indegree[neighbour] == 0){
                availCourses.push(neighbour);
               }
            }
        }

        return coursesTaken == numCourses;
    }
};
