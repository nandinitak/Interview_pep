#include <vector>
#include <numeric>
using namespace std;

/**
 * Definition for a binary tree node.
//  */
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
    bool p(TreeNode* root, vector<int>& ds, vector<vector<int>>& results, int t) {
        if (!root) return false; // Base case

        ds.push_back(root->val); // Add current node value to path

        int sum = accumulate(ds.begin(), ds.end(), 0); // Calculate sum of current path

        if (!root->left && !root->right) { // If it's a leaf node
            if (sum == t) return true; // If sum matches target, return true
        }

        bool left = p(root->left, ds, results, t);
        bool right = p(root->right, ds, results, t);

        ds.pop_back(); // Backtrack

        return left || right; // Return true if any path matches
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> results;
        vector<int> ds;
        if (!root) return false; // Corrected return type

        return p(root, ds, results, targetSum);
    }
};
