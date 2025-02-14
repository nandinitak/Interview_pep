
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
    void p(TreeNode* root, vector<int>& ds,vector<vector<int>>& results, int t,int sum) {
        if (!root)
            return;
        // int sum=0;
        ds.push_back(root->val);

        // int sum = accumulate(ds.begin(), ds.end(), 0);
         sum+=root->val;

        if (!root->left && !root->right) { 
            if (sum == t)
                results.push_back(ds); 
        }

        p(root->left, ds, results, t,sum);
        p(root->right, ds, results, t,sum);
        ds.pop_back();
        // return results;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> results;
        vector<int> ds;
        if (!root)
            return results;

        p(root, ds, results, targetSum,0);
        return results;
    }
};