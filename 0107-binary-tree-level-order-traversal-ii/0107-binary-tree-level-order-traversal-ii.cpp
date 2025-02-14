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


    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
       
        if(root==NULL) return results;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
           
            vector<int> ans;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* p =q.front();
                ans.push_back(p->val);
                q.pop();

                 if (p->left)q.push(p->left);
                 if (p->right)q.push(p->right);
            }
        results.insert(results.begin(),ans);
        ans.clear();
        }
      
        return results;
    }
};