
/**
 * Definition for a binary tree node.
//  */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//     right(right) {}
// };

class Solution {
public:
    vector<vector<int>> p(TreeNode* root, vector<int>& ds,
                          vector<vector<int>>& results, int t) {
        if (!root)
            return results;

        ds.push_back(root->val);

        int sum = accumulate(ds.begin(), ds.end(), 0);

        if (!root->left && !root->right) { // If it's a leaf node
            if (sum == t)
                //  return true;
                results.push_back(ds); // If sum matches target, return true
        }

        p(root->left, ds, results, t);
        p(root->right, ds, results, t);
        ds.pop_back();
        return results;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> results;
        vector<int> ds;
        if (!root)
            return results; // Corrected return type

        p(root, ds, results, targetSum);
        return results;
    }
};