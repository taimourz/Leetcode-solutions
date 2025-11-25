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
    int helper(TreeNode* root, int depth){
        if(root == NULL) return 0;
        
        int left = 1 + helper(root->left, depth);
        int right = 1 + helper(root->right, depth);

        int curr_max =  max(left, right);
        return depth = max(depth, curr_max);

    }
    int maxDepth(TreeNode* root) {
        return helper(root, 0);
    }
};

/*

isSameTree(p=3, depth=1)
│
├─→
│
├─→ isSameTree(p=9, depth=1)
│   │
│   ├─→ 1
│   │
│   ├─→ isSameTree(p=null, 0)
│   │   └─→ return 0
│   │
│   ├─→ isSameTree(p=null,)
│   │   └─→ return 0
│   │
│   └─→ return true
│
└─→ isSameTree(p=20, q=0)
    │
    ├─→ depth
    │
    ├─→ isSameTree(p=15, 0)
    │   └─→ return true
    │
    ├─→ isSameTree(p=7, q=null)
    │   └─→ return true
    │
    └─→ return true                           // Pop Frame 5
 
Final return: true
 


*/