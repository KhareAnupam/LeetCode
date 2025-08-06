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
    void helper(TreeNode* root, int targetSum,int sum, vector<int> v, vector<vector<int>>&ans){
        if(root==NULL) return;
        v.push_back(root->val);
        sum+=root->val;
        if(!root->left && !root->right){
            if(sum==targetSum){
                ans.push_back(v);
                return;
            }
        }
        helper(root->left,targetSum,sum,v,ans);
        helper(root->right,targetSum,sum,v,ans);


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>v;
        helper(root,targetSum,0,v,ans);
        return ans;
    }
};