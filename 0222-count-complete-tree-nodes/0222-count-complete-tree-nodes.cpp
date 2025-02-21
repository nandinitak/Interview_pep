class Solution {
public:
    int getheightL(TreeNode* node) {
        if (node == NULL) return 0;
        return 1 + getheightL(node->left); 
    }
    int getheightR(TreeNode* node) {
        if (node == NULL) return 0;
        return 1 + getheightR(node->right);
    }

    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        int h = 1; 
        int h1 = getheightL(root->left);
        int h2 = getheightR(root->right);

        if (h1 == h2) return (1<<(h1 + 1)) - 1; // Correct formula for full complete tree

        h += countNodes(root->left);  
        h += countNodes(root->right);

        return h;
    }
};
