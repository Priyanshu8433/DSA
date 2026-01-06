/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int sum=0;
        int maxi=INT_MIN;
        int minLev=-1;
        int curr=1;

        while(!q.empty()){
            TreeNode *node=q.front().first;
            int level=q.front().second;
            q.pop();
            if(level==curr) sum+=node->val;
            else{
                if(sum>maxi){
                    maxi=sum;
                    minLev=curr;
                }
                sum=node->val;
                curr=level;
            }
            if(node->left) q.push({node->left,level+1});
            if(node->right) q.push({node->right,level+1});
        }
        if(sum>maxi){
            maxi=sum;
            minLev=curr;
        }

        return minLev;
    }
};