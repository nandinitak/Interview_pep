/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            int minn=q.front().second;
            long long first,last;
            for (int i = 0; i < size; i++){
                TreeNode* p= q.front().first;
                long long curr = q.front().second-minn;
                q.pop();
                if(i==0) first=curr;
                if(i==size-1)last=curr;
                if(p->left){
                    q.push({p->left,curr*2+1});
                }
                if(p->right){
                    q.push({p->right,curr*2+2});
                }

            }
            ans=max(ans,last-first+1);
               
        }
        return ans;
    }
};