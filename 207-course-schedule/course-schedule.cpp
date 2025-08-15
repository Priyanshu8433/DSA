class Solution {
    bool dfs(int node, vector<vector<int>> &adjList, vector<int> &vis, vector<int> &pathVis){
        vis[node]=1;
        pathVis[node]=1;

        for(int x: adjList[node]){
            if(!vis[x]){
                if(dfs(x,adjList,vis,pathVis)) return true;
            }
            else{
                if(pathVis[x]) return true;
            }
        }

        pathVis[node]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);

        for(auto vec: prerequisites){
            adjList[vec[0]].push_back(vec[1]);
        }

        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i,adjList,vis,pathVis)) return false;
            }
        }
        return true;
    }
};