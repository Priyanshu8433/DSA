class Solution {
public:
    void helper(int idx, vector<int>& candidates, int target, vector<int> &temp, vector<vector<int>> &ans){
        int n=candidates.size();

        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(idx>=n) return;

        // take
        for(int i=idx; i<n; i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;

            if(candidates[i]>target) break;

            temp.push_back(candidates[i]);
            helper(i+1,candidates,target-candidates[i],temp,ans);
            temp.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0,candidates,target,temp,ans);
        return ans;
    }
};