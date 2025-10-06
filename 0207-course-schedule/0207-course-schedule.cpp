class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
        
            adjList[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            count++;
            for(int i = 0; i < adjList[node].size(); i++){
                indegree[adjList[node][i]]--;
                if(indegree[adjList[node][i]] == 0) q.push(adjList[node][i]);
            }
        }
        return numCourses == count;

    }
};