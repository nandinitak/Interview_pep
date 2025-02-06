class Solution {
public:
    void levelorder(vector<vector<int>>& result, TreeNode* root) {
        vector<int> ds;
        if (root == nullptr) return;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            
            if (temp != nullptr) {
                ds.push_back(temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            } else {
                result.push_back(ds);
                ds.clear();
                if (!q.empty()) q.push(nullptr);
            }
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelorder(result, root);
        return result;
    }
};
