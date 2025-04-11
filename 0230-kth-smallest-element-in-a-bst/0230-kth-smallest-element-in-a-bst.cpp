/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

    class Solution {
public:
    int count = 0;

    TreeNode* node(TreeNode* root, int k) {
        if (!root) return NULL;

        TreeNode* left = node(root->left, k);
        if (left) return left;

        count++;
        if (count == k) return root;

        TreeNode* right = node(root->right, k);
        return right;
    }

    int kthSmallest(TreeNode* root, int k) {
        TreeNode* result = node(root, k);
        return result ? result->val : -1;
    }
};
