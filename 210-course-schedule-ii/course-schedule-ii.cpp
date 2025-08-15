class Solution {
    bool dfs(int node, vector<vector<int>> &adjList, vector<int> &vis, vector<int> &pathVis, stack<int> &s){
        vis[node]=1;
        pathVis[node]=1;

        for(int x: adjList[node]){
            if(!vis[x]){
                if(dfs(x,adjList,vis,pathVis,s)) return true;
            }
            else{
                if(pathVis[x]) return true;
            }
        }
        s.push(node);
        pathVis[node]=0;
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*Algorithm*/
        /*
         Topological order and if there's a cycle then it's not possible
        */

        stack<int> s;
        vector<vector<int>> adjList(numCourses);
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);

        for(auto vec: prerequisites){
            adjList[vec[1]].push_back(vec[0]);
        }

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i,adjList,vis,pathVis,s)) return {};
            }
        }

        vector<int> res;
        while(!s.empty()){
            int x=s.top();
            s.pop();
            res.push_back(x);
        }

        return res;
    }
};