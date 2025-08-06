/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool find(TreeNode* root, TreeNode* p){
        if(root==NULL) return false;
        if(root==p) return true;
        if(find(root->left,p)) return true;
        if(find(root->right,p)) return true;
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        else if(find(root->left,p) && find(root->right,q)) return root;
        else if(find(root->right,p) && find(root->left,q)) return root;
        else if(find(root->left,p) && !find(root->right,q)) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }
};