class Solution {
public:
    void helper(int idx, vector<int>& candidates, int target, vector<int> &temp, vector<vector<int>> &ans){
        int n=candidates.size();
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(idx>=n) return;

        if(candidates[idx]<=target){
            temp.push_back(candidates[idx]);
            helper(idx,candidates,target-candidates[idx],temp,ans);
            temp.pop_back();
        }

        helper(idx+1,candidates,target,temp,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0,candidates,target,temp,ans);

        return ans;
    }
};