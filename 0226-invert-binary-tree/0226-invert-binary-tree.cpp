
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
        if (root == nullptr) return nullptr; // Base case: if tree is empty, return null

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> levelNodes; // Store pointers to nodes of the current level

            // Step 1: Traverse the current level and store node pointers
            for (int i = 0; i < size; i++) {
                TreeNode* p = q.front();
                q.pop();
                levelNodes.push_back(p); // Store node pointers

                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }

            // Step 2: Reverse the pointers in `levelNodes` to invert child relationships
            reverse(levelNodes.begin(), levelNodes.end());

            // Step 3: Swap left and right pointers of each node
            for (TreeNode* node : levelNodes) {
                swap(node->left, node->right);
            }
        }

        return root; // Return the inverted tree
    }
};
