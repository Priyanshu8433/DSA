class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        int n=numCourses;
        vector<vector<int>> adjList(n);

        for(auto vec: prereq){
            adjList[vec[0]].push_back(vec[1]);
        }
        vector<int> inDegree(n,0);
        for(int i=0; i<n; i++){
            for(auto it: adjList[i]) inDegree[it]++;
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            if(inDegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            n--;
            for(auto it: adjList[node]){
                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }

        return n==0;
    }
};