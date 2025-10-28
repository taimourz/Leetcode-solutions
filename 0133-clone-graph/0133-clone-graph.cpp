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
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        if (node->neighbors.empty()) {
            return new Node(node->val);
        }
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*, Node*> mp;
        mp[node] = new Node(node->val);

        while(!q.empty()){

            auto current_node = q.front(); q.pop();
            vector<Node*> neighors = current_node->neighbors;




            for(int i = 0; i < neighors.size(); i++){

                Node* current_neigh = neighors[i];

                if(!mp.count(current_neigh)){
                    mp[current_neigh] = new Node(current_neigh->val);
                    q.push(current_neigh);
                }


                mp[current_node]->neighbors.push_back(mp[current_neigh]);

            }

        }
        return mp[node];



    }
};