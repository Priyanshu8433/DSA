class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);

        for(auto v: prerequisites){
            adjList[v[1]].push_back(v[0]);
        }

        vector<int> inDegree(numCourses,0);

        for(int i=0; i<numCourses; i++){
            for(int it: adjList[i]) inDegree[it]++;
        }

        queue<int> q;
        vector<int> ans;

        for(int i=0; i<numCourses; i++){
            if(inDegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adjList[node]){
                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }

        if(numCourses!=ans.size()) return {};
        return ans;
    }
};