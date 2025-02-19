// #include <vector>
// #include <queue>
// #include <algorithm> // For reverse()

// using namespace std;

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
    TreeNode* invertTree(TreeNode* root) {
        vector<int> ds;
        if (root == nullptr) return nullptr; // If tree is empty, return empty vector

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* p = q.front();
                q.pop();
               swap(p->left,p->right);

                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
            
            // Corrected reverse() usage
            // reverse(ds.begin() + ds.size() - size, ds.end());
        }

        return root;
    }
};
