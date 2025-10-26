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
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return {};

        TreeNode* left = helper(root->left,p,q);
        TreeNode* right = helper(root->right,p,q);        
        if(left && right) return root;
        if(root==p || root==q) return root;
        
         return left ? left : right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool p_found = false;
        bool q_found = false;        
        return helper(root,p,q);

    }
};

/*

think in terms of what is left and right returning
we will make decision when we have both left and right.
if we find p or q, then we need to bubble that node upward.

*/