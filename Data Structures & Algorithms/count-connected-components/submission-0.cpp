class Solution {
public:
    void dfs(vector<vector<int>>& adjList, int node, vector<bool>& visited){
        if(visited[node]) return;

        visited[node] = true;
        for(int neighbor: adjList[node]){
            if(!visited[neighbor]){
                dfs(adjList, neighbor, visited);
            }
        }

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        //dfs for each node with visited - ++ everytme ! visited is encountered - mark neighbours as visited

        int ne = edges.size();

        if(ne == 0) return n;
        vector<vector<int>>adjList(n);

        for(int j = 0; j<ne; ++j){
            adjList[edges[j][0]].push_back(edges[j][1]);
            adjList[edges[j][1]].push_back(edges[j][0]);
        }
        vector<bool>visited(n,false);
        int cc = 0;
        for(int i = 0; i<n; ++i){
            if(!visited[i]){
                cc++;
                dfs(adjList, i, visited);
            }
        }

        return cc;
    }
};
