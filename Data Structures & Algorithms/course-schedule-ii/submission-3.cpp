class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        int np = prereq.size();
        // bfs - indegree, adjList
        vector<vector<int>> dependencyList(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (int i = 0; i < np; ++i) {
            dependencyList[prereq[i][0]].push_back(prereq[i][1]);
            inDegree[prereq[i][1]]++;
        }

        queue<int> qc;

        for (int j = 0; j < numCourses; ++j) {
            if (inDegree[j] == 0) {
                qc.push(j);
            }
        }

        vector<int> coursesTaken(numCourses);
        int coursesSoFar = 0;
        while (!qc.empty()) {
            int currCourse = qc.front();
            qc.pop();
            coursesTaken[numCourses - coursesSoFar - 1]=currCourse;
            coursesSoFar++;

            for (int dependentCourse : dependencyList[currCourse]) {
                inDegree[dependentCourse]--;
                if (inDegree[dependentCourse] <= 0) {
                    qc.push(dependentCourse);
                }
            }
            
        }

        if (coursesSoFar != numCourses) {
            return {};
        }

        return coursesTaken;
    }
};
