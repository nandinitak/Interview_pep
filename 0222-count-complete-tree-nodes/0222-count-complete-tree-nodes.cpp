class Solution {
public:
    int getheightL(TreeNode* node) {
        if (node == NULL) return 0;
        return 1 + getheightL(node->left); // Traverse left to get height
    }
    int getheightR(TreeNode* node) {
        if (node == NULL) return 0;
        return 1 + getheightR(node->right); // Traverse left to get height
    }

    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        int h = 1; // Start from 1 to count the current node
        int h1 = getheightL(root->left);
        int h2 = getheightR(root->right);

        if (h1 == h2) return pow(2, h1 + 1) - 1; // Correct formula for full complete tree

        h += countNodes(root->left);  // Accumulate left subtree count
        h += countNodes(root->right); // Accumulate right subtree count

        return h;
    }
};
