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
    TreeNode* solve(vector<int>& post, vector<int>& in, int inorderS, int inorderE, int& index, int n, unordered_map<int,int> &mpp) {
        if (index< 0 || inorderS > inorderE) {
            return nullptr;
        }

        int element = post[index];
        index--;  // Move to the next preorder element

        TreeNode* root = new TreeNode(element);
        int position = mpp[element];
        root->right = solve(post, in, position + 1, inorderE, index, n,mpp);
        root->left = solve(post, in, inorderS, position - 1, index, n,mpp);
     

        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = post.size();
        int inorderS = 0;
        int inorderE = n - 1;
        int index = n-1;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[in[i]]=i;
        }
        return solve(post, in, inorderS, inorderE, index, n,mpp);
    }
};