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
    int MOD=1e9+7;

    int sum(TreeNode* root){
        if(!root) return 0;

        int left=sum(root->left);
        int right=sum(root->right);

        return left+right+root->val;
    }

    int solve(TreeNode* root, int total, long long &maxi){
        if(!root) return 0;

        int left=solve(root->left,total,maxi);
        int right=solve(root->right,total,maxi);

        int subSum=left+right+root->val;
        int othSum=total-subSum;
        long long prod=1ll*subSum*othSum;
        if(prod>maxi) maxi=prod;

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        int totalSum=sum(root);
        long long maxi=0;
        solve(root,totalSum,maxi);
        return maxi%MOD;
    }
};