
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;  // Map to store postorder indices
        int Index = 0;  // Keeps track of preorder index
        
        // Store index of each element in postorder
        for (int i = 0; i < postorder.size(); i++) {
            mpp[postorder[i]] = i;
        }

        return buildTree(preorder, postorder, Index, 0, postorder.size() - 1, mpp);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int& Index, int left, int right, unordered_map<int, int>& mpp) {
        if (Index >= preorder.size() || left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[Index++]);  // Create root node
        
        if (left == right) return root;  // If it's a leaf node, return

        int mid = mpp[preorder[Index]];  // Find left child position in postorder

        root->left = buildTree(preorder, postorder, Index, left, mid, mpp);
        root->right = buildTree(preorder, postorder, Index, mid + 1, right - 1, mpp);

        return root;
    }
};
