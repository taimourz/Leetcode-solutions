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
    bool helper(long long negative_infinity, TreeNode* root, long long positive_infinity){
        if(root == NULL) return true;
        if(root->val >= positive_infinity || root->val <= negative_infinity){
            return false;
        } 

        bool left = helper(negative_infinity, root->left, root->val);
        bool right = helper(root->val, root->right, positive_infinity);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        
        long long negative_infinity = LLONG_MIN;
        long long positive_infinity = LLONG_MAX;
        return helper(negative_infinity, root, positive_infinity);
        
    }
};