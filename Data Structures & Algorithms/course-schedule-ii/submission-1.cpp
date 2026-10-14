class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>orderedCourses;
        int n = prerequisites.size();
        if(n == 0) {
            for(int i = 0; i < numCourses; ++i){
                orderedCourses.push_back(i);
            }
            return orderedCourses;
        }
        vector<vector<int>>adjList(numCourses);
        vector<int>dependency(numCourses,0);
        for(int i = 0; i < n ; ++i){
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];

            adjList[prereq].push_back(course);
            dependency[course]++;
        }

        queue<int>courseTaken;

        for(int course = 0; course<numCourses; ++course){
            if(dependency[course] == 0){
                courseTaken.push(course);
            }
        }

        while(!courseTaken.empty()){
            int completed = courseTaken.front();
            courseTaken.pop();
            orderedCourses.push_back(completed);

            for(int dependentCourse: adjList[completed]){
                dependency[dependentCourse]--;
                if(dependency[dependentCourse] == 0){
                    courseTaken.push(dependentCourse);
                }
            }
        }

        return orderedCourses.size() != numCourses ? vector<int>{} : orderedCourses;


    }
};
