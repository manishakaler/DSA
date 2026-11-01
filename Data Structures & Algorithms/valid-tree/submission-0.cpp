class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adjList,vector<bool>& visited){
        if(visited[node]) return false; 

        visited[node] = true;
        for(int nei: adjList[node]){
            if(nei == parent) continue;

            if(visited[nei]) return false;

            if(!dfs(nei,node, adjList, visited)){
                return false;
            }
        }

        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        //dfs - if visited is true and that node is called again - cycle - cycle detection , disconnected graph is also false
        //undirected - two way

        int ne = edges.size();

        if(ne == 0 && n > 1 ) return false;

        vector<bool>visited(n,false);
        vector<vector<int>>adjList(n);

        for(int i = 0; i < ne; ++i){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        if(!dfs(0,-1,adjList,visited)){
            return false;
        }

        for(int j = 0; j < n; ++j){
            if(!visited[j]){
               return false;
            }
        }

        return true;
    }
};
