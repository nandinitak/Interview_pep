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
   
    int dfsheight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int h1=dfsheight(root->left);
        int h2=dfsheight(root->right);
        if(h1==-1||h2==-1)return -1;
        if(abs(h1-h2)>1)return -1;
        return max(h1,h2)+1;
    
    }
     bool isBalanced(TreeNode* root) {
       return dfsheight(root)!=-1;
       
    }

};