class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for(auto prerequisite:prerequisites){
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }
queue<int> q;
//push all nodes with zero indegree in queue
for(int i=0;i<numCourses;i++){
    if(indegree[i]==0)q.push(i);
}
int nodesVisited=0;
while(!q.empty()){
    int node=q.front();
    q.pop();
    nodesVisited++;
    for(auto &neighbour:adj[node]){
        //delete the edge " node->neighbour"
        indegree[neighbour]--;
        if(indegree[neighbour]==0)q.push(neighbour);
    }
}
return nodesVisited==numCourses;
    }
};