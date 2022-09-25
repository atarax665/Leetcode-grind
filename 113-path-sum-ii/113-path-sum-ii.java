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
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        
     List<List<Integer>> ans= new ArrayList<>();
        ArrayList<Integer> b= new ArrayList<>();
        dfs(root,targetSum,ans,b);
        return ans;
        
    }
    
    private static void dfs(TreeNode rr,int ts,   List<List<Integer>> ans,ArrayList<Integer> b)
    {
        if(rr ==null)
        {
           return;
        }
         b.add(rr.val);
        if(ts==rr.val && rr.left==null && rr.right==null)
            ans.add(new ArrayList<Integer>(b));
        
        else{
            dfs(rr.left,ts-rr.val,ans,b);
        dfs(rr.right,ts-rr.val,ans,b);
        }
        
         b.remove(b.size()-1);
    }
}