#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    // int findPosition(vector<int>& in, int element, int n, unordered_map<int,int>mpp) {
    //     for (int i = 0; i < n; i++) {
    //         if (in[i] == element) {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    TreeNode* solve(vector<int>& pre, vector<int>& in, int inorderS, int inorderE, int& index, int n, unordered_map<int,int> &mpp) {
        if (index >= n || inorderS > inorderE) {
            return nullptr;
        }

        int element = pre[index];
        index++;  // Move to the next preorder element

        TreeNode* root = new TreeNode(element);
        int position = mpp[element];

        root->left = solve(pre, in, inorderS, position - 1, index, n,mpp);
        root->right = solve(pre, in, position + 1, inorderE, index, n,mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        int inorderS = 0;
        int inorderE = n - 1;
        int index = 0;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[in[i]]=i;
        }
        return solve(pre, in, inorderS, inorderE, index, n,mpp);
    }
};
