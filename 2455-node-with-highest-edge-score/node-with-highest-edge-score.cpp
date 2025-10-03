class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<int,long long> mp;

        int n=edges.size();

        for(int i=0; i<n; i++){
            mp[edges[i]]+=i;
        }

        int maxEle=-1;
        long long maxValue=-1;
        for(auto it: mp){
            if(it.second>maxValue){
                maxEle=it.first;
                maxValue=it.second;
            }
            else if(it.second==maxValue){
                if(it.first<maxEle){
                    maxEle=it.first;
                    maxValue=it.second;
                }
            }
        }

        return maxEle;
    }
};