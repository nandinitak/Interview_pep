#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                parent_track[node->left] = node;
            }
            if (node->right) {
                q.push(node->right);
                parent_track[node->right] = node;
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParent(root, parent_track);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curlevel = 0;

        while (!q.empty()) {
            int size = q.size();
           
            if (curlevel == k) break; // Stop at exact distance
           
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                // Visit left child
                if (current->left && !visited[current->left]) {
                    visited[current->left] = true;
                    q.push(current->left);
                }

                // Visit right child
                if (current->right && !visited[current->right]) {
                    visited[current->right] = true;
                    q.push(current->right);
                }

                // Visit parent
                if (parent_track.count(current) && !visited[parent_track[current]]) {
                    visited[parent_track[current]] = true;
                    q.push(parent_track[current]);
                }
            }
             curlevel++;
            
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};
