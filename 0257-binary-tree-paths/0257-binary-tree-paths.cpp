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
    void p(TreeNode* root, vector<string>&str, string ds){
        if(!root) return;
         
         string r=to_string(root->val);
         
         ds+=r;

        if(!root->left &&!root->right) {
            str.push_back(ds);
            return;
        }
        if(!ds.empty())
         ds+=("->");
       
            p(root->left,str,ds);
            p(root->right,str,ds);
            ds.pop_back();
         
         
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> str;
        // string ds="";
        if(root==NULL) return {};
        p(root, str,"");
        return str;
    }
};