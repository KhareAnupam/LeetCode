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
    void helper(TreeNode* root, int targetSum,long long sum, int & count){
        if(root==NULL) return;
        // v.push_back(root->val);
        sum+=(long long)root->val;
        if(sum==(long long)targetSum){
            count++;
        }
        helper(root->left,targetSum,sum, count);
        helper(root->right,targetSum,sum, count);
        
    }
    // void helper2(TreeNode* root, int targetSum, int &count){
    //     if(root==NULL) return ;
    //     helper(root,targetSum,0,count);
    //     helper2(root->left,targetSum,count);
    //     helper2(root->right,targetSum,count);
        
    // }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int count=0;
        helper(root,targetSum,0, count);
        count+= pathSum(root->left,targetSum);
        count+= pathSum(root->right,targetSum);
        return count;

    }
};