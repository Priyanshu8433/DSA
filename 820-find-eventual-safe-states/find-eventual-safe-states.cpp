class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> inDegree(n,0);
        vector<vector<int>> adjRev(n);

        for(int i=0; i<n; i++){
            for(auto it: graph[i]){
                adjRev[it].push_back(i);
            }
        }

        for(int i=0; i<n; i++){
            for(auto it: adjRev[i]) inDegree[it]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(inDegree[i]==0) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adjRev[node]){
                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};