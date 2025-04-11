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
    int kthSmallest(TreeNode* root, int k) {
    if (!root) return -1;

    queue<TreeNode*> q;
    vector<int> values;

    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        values.push_back(node->val);

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    sort(values.begin(), values.end()); 

    return values[k - 1]; 
}
};