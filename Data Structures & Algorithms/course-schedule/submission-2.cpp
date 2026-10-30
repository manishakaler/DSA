class Solution{
    public : 
    bool canFinish(
int numCourses, vector<vector<int>>& prerequisites){// kahn’s algo – queue plus indegree
    int p = prerequisites.size();
    if (p == 0) return true;
    vector<vector<int>> adjList(numCourses);
    vector<int> indegree(numCourses, 0);

    for (int i = 0; i < prerequisites.size(); ++i) {
        adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegree[prerequisites[i][0]]++;
    }

    queue<int> eligibleCourses;

    for (int x = 0; x < numCourses; ++x) {
        if (indegree[x] == 0) {
            eligibleCourses.push(x);
        }
    }
    int coursesTaken = 0;
    while (!eligibleCourses.empty()) {
        int currCourse = eligibleCourses.front();
        eligibleCourses.pop();
        coursesTaken++;
        for (int depCourse : adjList[currCourse]) {
            indegree[depCourse]--;
            if (indegree[depCourse] == 0) {
                eligibleCourses.push(depCourse);
            }
        }
    }

    return numCourses == coursesTaken ? true : false;
    }
};
