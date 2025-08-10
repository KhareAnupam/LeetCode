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
    // TreeNode* helper(TreeNode* root){
    //     if(root==NULL) return NULL;
    //     if(root->left){
    //         TreeNode* temp= root->right;
    //         root->right = helper(root->left);
    //         TreeNode* temp2 = root->right;
    //         while(temp2->right) temp2=temp2->right;
    //         temp2->right = temp; 
    //         root->left=NULL;
    //     }
    //     helper(root->right);
    //     return root;
    // }
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* cur = root;
        while(cur){
            if(cur->left){
                TreeNode* r = cur->right;
                cur->right=cur->left;
                TreeNode* pred=cur->left;
                while(pred->right) pred=pred->right;
                pred->right=r;
                cur->left=NULL;
                cur=cur->right;
            }
            else{
                cur=cur->right;
            }
        }
    }
};