class Solution {
public:


bool hasNoCyclicDependency(int currCourse, vector<int>& visited, vector<vector<int>>& dependencyList, vector<int>& coursesTaken) {
	if(visited[currCourse] == 1) {
		return false; //cycle detection - course is already marked as visiting}
	}
	if(visited[currCourse] == 2) {
		return true; //courses already taken
	}

	visited[currCourse] = 1;

	for(int prerequisite : dependencyList[currCourse]) {
		if(!hasNoCyclicDependency(prerequisite, visited, dependencyList, coursesTaken)) {
			return false;
		}
	}

	visited[currCourse] = 2;
	coursesTaken.push_back(currCourse);
	return true;
}

// time complexity : numCourses - no of vertices, e- no of edges - O(numCourses+e)
//space complexity : O(V+E) for space  and O(V+E) auxiliary space

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites ) {
	vector<int>visited(numCourses,0);
	vector<vector<int>>dependencyList(numCourses);
	vector<int>coursesTaken;

	for(int i = 0; i < prerequisites.size(); ++i) {
		dependencyList[prerequisites[i][0]].push_back(prerequisites[i][1]);
	};

	for(int c = 0; c < numCourses; ++c) {
		if(!hasNoCyclicDependency(c, visited, dependencyList, coursesTaken)) {
			return {};
		}
	}

	return coursesTaken;
}
};
