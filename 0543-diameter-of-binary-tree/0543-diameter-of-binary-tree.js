/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function(root) {
    let max_diameter = 0

  function helper(root){
       if(root == null) return 0

      // tree = new Tree(root)
      debugger

      let left  =  helper(root.left);
      let right =  helper(root.right);

      let current_diameter = left + right
      max_diameter = Math.max(current_diameter, max_diameter)
      return 1 + Math.max(left, right)
  }

  helper(root)
  return max_diameter
};






/*

          1
         /  \
        2    3
       / \
      4   5



i can have longest path on left side and longest on right 
Then i can add them up. 





*/