
class Solution {
public:
    void parseString(string& s, vector<pair<int, int>>& vec) {
        int count = 0, n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '-') {
                count++;
            } else {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--; // Adjust index as the for-loop increments it

                vec.push_back({num, count});
                count = 0;
            }
        }
    }

    TreeNode* buildTree(vector<pair<int, int>>& vec) {
        if (vec.empty()) return nullptr;

        vector<TreeNode*> parents;
        TreeNode* root = new TreeNode(vec[0].first);
        parents.push_back(root);

        for (int i = 1; i < vec.size(); i++) {
            int val = vec[i].first;
            int depth = vec[i].second;
            TreeNode* newNode = new TreeNode(val);

            if (depth >= parents.size()) {
                parents.resize(depth + 1, nullptr);
            }

            if (depth > 0 && parents[depth - 1] != nullptr) {
                TreeNode* parent = parents[depth - 1];
                if (!parent->left)
                    parent->left = newNode;
                else
                    parent->right = newNode;
            }

            parents[depth] = newNode;
        }

        return root;
    }

    TreeNode* recoverFromPreorder(string s) {
        vector<pair<int, int>> vec;
        parseString(s, vec);
        return buildTree(vec);
    }
};
