/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* og, unordered_map<Node*,Node*>& cmap){
        if(cmap.find(og)!= cmap.end()){
            return;
        }
        Node* clone = new Node(og->val);
        cmap[og] = clone;
        

        for(Node* neighbor : og->neighbors){
            if(cmap.find(neighbor)== cmap.end()){
                Node* c = new Node();
                dfs(neighbor, cmap);
            }
            clone->neighbors.push_back(cmap[neighbor]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<Node*,Node*>cmap;

        dfs(node, cmap);

        return cmap[node];
    }
};
