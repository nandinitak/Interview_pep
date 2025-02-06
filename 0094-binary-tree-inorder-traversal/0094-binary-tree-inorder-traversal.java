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
import java.util.*;

class Solution {
    public void inorder(TreeNode root, Vector<Integer> ans) {
        if (root == null) return;
      
        inorder(root.left, ans);
          ans.add(root.val);
        inorder(root.right, ans);
    }

    public Vector<Integer> inorderTraversal(TreeNode root) {
        Vector<Integer> ans = new Vector<>();
        inorder(root, ans);
        return ans;
    }
}
