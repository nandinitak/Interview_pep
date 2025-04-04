/**if
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
    TreeNode* lca(TreeNode* root,TreeNode*p, TreeNode* q){
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        TreeNode* left=lca(root->left,p,q);
        TreeNode* right=lca(root->right,p,q);
        if(left&&right) return root;
        return left ? left:right;

    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<TreeNode*>> result;
        while(!q.empty()){
            int size=q.size();
            vector<TreeNode*> p;
            for(int i=0;i<size;i++){  
            TreeNode* temp = q.front();
            q.pop();
            p.push_back(temp);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            }
            result.push_back(p);
        }
        vector<TreeNode*> temp=result.back();
        if(temp.size()==1) return temp[0];
        return lca(root,temp.front(),temp.back());

    }
};