/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(depth == 1){
            TreeNode node = new TreeNode(val);
            node.left = root;
            return node;
        }
        return add(root, val, 1, depth);
    }
    
    public TreeNode add(TreeNode root, int val, int current, int depth){
        if(root == null){
            return null;
        }
        if(current == depth - 1){
            TreeNode leftNode = new TreeNode(val);
            TreeNode rightNode = new TreeNode(val);
            leftNode.left = root.left;
            rightNode.right = root.right;
            root.left = leftNode;
            root.right = rightNode;
            return root;
        }
        root.left = add(root.left, val, current + 1, depth);
        root.right = add(root.right, val, current + 1, depth);
        return root;
    }
}