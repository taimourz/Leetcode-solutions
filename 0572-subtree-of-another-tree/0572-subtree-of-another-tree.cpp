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
    bool helper(TreeNode* root, vector<string>& subtree){
        if(root == NULL) return false;

        if(to_string(root->val) == subtree[0]){
            vector<string> newtree;
            traverseTree(root, newtree);
            if(newtree == subtree) return true;
        }

        bool left = helper(root->left, subtree);
        bool right = helper(root->right, subtree);
        return left || right;
    }
    void traverseTree(TreeNode* subRoot, vector<string>& subtree){
        if(subRoot == NULL){
            subtree.push_back("null");
            return;
        } 

        subtree.push_back(to_string(subRoot->val));
        traverseTree(subRoot->left, subtree);
        traverseTree(subRoot->right, subtree);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<string> subtree;
        traverseTree(subRoot, subtree);
        return helper(root, subtree);
    }
};