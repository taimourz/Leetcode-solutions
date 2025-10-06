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
        int count = 0;
        for(int i = 0; i < indegree.size(); i++) if(indegree[i] == 0) q.push(i);

        while(!q.empty()){

            auto element = q.front(); q.pop(); count++;

            for(int i = 0; i < adjList[element].size(); i++){
                indegree[adjList[element][i]]--;
                if(indegree[adjList[element][i]] == 0){
                    q.push(adjList[element][i]);
                }
            }
        }
        return count == numCourses;

        

    }
};



/*
we need to create adj list
then we are going to need a vector thats gonna store the indegree
initially all nodes have indegree 0
then we would need to have a queue, this will contain only nodes indegree 0
then we take each element from the queue one by one. 
then get that element from the adj list 
now decrement the indegree and see if it is still equal to 0. if yes then push in the queu.
at the end, if no of courses == 0, then it means that topological sort is correct and true


*/